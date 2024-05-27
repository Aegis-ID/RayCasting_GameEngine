/*
** EPITECH PROJECT, 2024
** display
** File description:
** CSFML
** J'ai mal au crane
** Jugez pas les répets
*/

#include <stdio.h>

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <math.h>

#include "lib.h"
#include "game.h"
#include "settings.h"

#include "const/textures.h"

bool is_wall(int m_pos)
{
    if ((m_pos > 0) && (m_pos <= TEXTURES_NB))
        return true;
    return false;
}

static void set_text_color(
    const size_t pixel, const size_t *texture, const float shade)
{
    sfColor color = {0, 0, 0, 0};

    color.r = texture[pixel + 1] * shade;
    color.g = texture[pixel + 2] * shade;
    color.b = texture[pixel + 3] * shade;
    glColor3ub(color.r, color.g, color.b);
    return;
}

static void update_offset(int *offset)
{
    if (*offset < 0)
        *offset += SKY_WD;
    *offset %= SKY_WD;
    return;
}

void draw_sky(const sfVector2i res, float p_angle, const float shade)
{
    size_t pixel = 0;
    int pixel_s = res.x / SKY_WD + 1;
    int offset = 0;

    for (size_t y = 0; y < SKY_HT; ++y) {
        for (size_t x = 0; x < SKY_WD; ++x) {
            offset = p_angle - x;
            update_offset(&offset);
            pixel = (y * SKY_WD + offset) * 3;
            set_text_color(pixel, SKY_TEXT, shade);
            glPointSize(pixel_s);
            glBegin(GL_POINTS);
            glVertex2i(x * pixel_s, y * pixel_s);
            glEnd();
        }
    }
    return;
}

static float get_text_width(
    sfVector2i res, const float player_fov, const float deg_angle)
{
    float fov = deg_to_rad(get_fov(res, player_fov));
    float black_magic = (float)res.x / 2.0f / tan(fov / 2.0f);
    float ra_fix = cos(deg_to_rad(deg_angle));

    return black_magic / 2 * TEXTURES_S / ra_fix;
}

static void draw_floor(entity_t *p, ray_t *r, textures_t *t, sfVector2i res)
{
    float rad = deg_to_rad(r->angle);
    float size =
        get_text_width(res, r->fov, get_deg(p->angle - r->angle));
    float dy = 0;
    size_t pixel = 0;

    for (t->iter = t->line_off + t->line_ht; t->iter < res.y; ++t->iter) {
        dy = t->iter - ((float)res.y / 2.0f);
        t->pos.x = p->pos.x / 2 + cos(rad) * size / dy;
        t->pos.y = p->pos.y / 2 - sin(rad) * size / dy;
        pixel = (((int)(t->pos.y) & (TEXTURES_S - 1)) * TEXTURES_S
            + ((int)(t->pos.x) & (TEXTURES_S - 1))) * 3;
        set_text_color(pixel, FLOOR_TEXT, CONST_SHADE * BRIGHTNESS);
        glPointSize(PIXEL_S);
        glBegin(GL_POINTS);
        glVertex2i(r->iter * PIXEL_S, t->iter);
        glEnd();
    }
    return;
}

static void draw_vertical_line(textures_t *t,
    int iter, size_t texture_type)
{
    size_t pixel = 0;

    for (int y = 0; y < t->line_ht; ++y) {
        pixel = ((int)t->pos.y * TEXTURES_S + (int)t->pos.x) * 3;
        set_text_color(pixel, ALL_TEXTURES[texture_type], t->shade);
        glPointSize(PIXEL_S);
        glBegin(GL_POINTS);
        glVertex2i(iter * PIXEL_S, y + t->line_off);
        glEnd();
        t->pos.y += t->step;
    }
    return;
}

static void check_side(ray_t *r, textures_t *t)
{
    if (r->v_dist >= r->h_dist) {
        t->pos.x = (int)(r->pos.x / 2) % TEXTURES_S;
        if (r->angle > 180)
            t->pos.x = (TEXTURES_S - 1) - t->pos.x;
    } else {
        t->pos.x = (int)(r->pos.y / 2) % TEXTURES_S;
        if (r->angle > 90 && r->angle < 270)
            t->pos.x = (TEXTURES_S - 1) - t->pos.x;
    }
    return;
}

static textures_t setup_textures(map_t *m, ray_t *r, sfVector2i res)
{
    textures_t t = {0};

    t.shade = (1 / r->dist * RENDER_DIST) * BRIGHTNESS;
    if (t.shade > 1)
        t.shade = 1;
    else if (t.shade < 0)
        t.shade = 0;
    t.line_ht = m->cell_size * res.y / r->dist;
    t.step = TEXTURES_S / (float)t.line_ht;
    if (t.line_ht > res.y) {
        t.pos.y = (t.line_ht - res.y) / 2 * t.step;
        t.line_ht = res.y;
    }
    t.line_off = res.y / 2 - (t.line_ht >> 1);
    return t;
}

void draw_ray(graphics_t *rays, sfVector2i res)
{
    entity_t *p = &rays->player;
    map_t *m = &rays->map;
    ray_t *r = &rays->ray;
    textures_t t = setup_textures(m, r, res);

    check_side(r, &t);
    draw_vertical_line(&t, r->iter, r->t_type);
    draw_floor(p, r, &t, res);
    return;
}
