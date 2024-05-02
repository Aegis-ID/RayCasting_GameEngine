/*
** EPITECH PROJECT, 2024
** display
** File description:
** C'est là que commence la vraie magie noire...
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <math.h>
#include "lib.h"
#include "game/structs.h"
#include "ray_casting/funcs.h"
#include "settings/structs.h"
#include "textures/structs.h"
#include "textures/textures.h"

bool is_wall(int map_position)
{
    if ((map_position > 0) && (map_position <= TEXTURES_NB))
        return true;
    return false;
}

static void colorize_texture(int wall_type, float color)
{
    enum texture_type;

    wall_type += 1;
    if (wall_type == CHECKERBOARD)
        glColor3f(color, color / 2, color / 2);
    if (wall_type == BRICK)
        glColor3f(color, color, color / 2);
    if (wall_type == WINDOW)
        glColor3f(color / 2, color / 2, color);
    if (wall_type == DOOR)
        glColor3f(color / 2, color, color / 2);
    return;
}

static void setup_texture_pos(player_t *p, rays_t *r, textures_t *t, float dy)
{
    float deg = deg_to_rad(r->angle);
    float ra_fix = cos(deg_to_rad(update_angle(p->angle - r->angle)));
    size_t size = 158;
    // Size is supposed to be (Line width / 2) / tan(fov / 2)

    t->pos.x = (p->pos.x / 2) + cos(deg) * size *
        TEXTURES_S / dy / ra_fix;
    t->pos.y = (p->pos.y / 2) - sin(deg) * size *
        TEXTURES_S / dy / ra_fix;
    return;
}

static void draw_ceil(rays_t *r, textures_t *t, display_t *d,
    int texture_type)
{
    size_t dp_height = (d->resolution.y / 2);
    size_t dp_width = (d->resolution.x / 2);
    float color =
        ALL_TEXTURES[texture_type][((int)(t->pos.y) & (TEXTURES_S - 1)) *
        TEXTURES_S + ((int)(t->pos.x) & (TEXTURES_S - 1))] * 0.7;

    colorize_texture(texture_type, color);
    glPointSize(LINE_WIDTH);
    glBegin(GL_POINTS);
    glVertex2i(r->r_iter * LINE_WIDTH + dp_width, dp_height - t->t_iter);
    glEnd();
    return;
}

static void draw_floor(rays_t *r, textures_t *t, display_t *d,
    int texture_type)
{
    size_t dp_width = (d->resolution.x / 2);
    float color =
        ALL_TEXTURES[texture_type][((int)(t->pos.y) & (TEXTURES_S - 1)) *
        TEXTURES_S + ((int)(t->pos.x) & (TEXTURES_S - 1))] * 0.7;

    colorize_texture(texture_type, color);
    glPointSize(LINE_WIDTH);
    glBegin(GL_POINTS);
    glVertex2i(r->r_iter * LINE_WIDTH + dp_width, t->t_iter);
    glEnd();
    return;
}

static void draw_fc(player_t *p, rays_t *r, textures_t *t, display_t *d)
{
    enum texture_type;
    size_t dp_height = (d->resolution.y / 2);

    for (size_t y = t->line_off + t->line_ht; y < dp_height; ++y) {
        t->iter = y;
        setup_texture_pos(p, r, t, y - (dp_height / 2));
        draw_floor(r, t, d, BRICK);
        draw_ceil(r, t, d, BRICK);
    }
    return;
}

static void setup_wall(rays_t *r, textures_t *t)
{
    t->pos.y = t->offset.y * t->step.y;
    if (r->shade == SHADE) {
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

static void draw_walls(rays_t *r, textures_t *t, display_t *d)
{
    float color = 0;

    setup_wall(r, t);
    for (size_t y = 0; y < t->line_ht; ++y) {
        color =
            ALL_TEXTURES[r->wall_type][(int)(t->pos.y) *
            TEXTURES_S + (int)(t->pos.x)] * r->shade;
        colorize_texture(r->wall_type, color);
        glPointSize(LINE_WIDTH);
        glBegin(GL_POINTS);
        glVertex2i(r->r_iter * LINE_WIDTH + (d->resolution.x / 2),
            y + t->line_off);
        glEnd();
        t->pos.y += t->step.y;
    }
    return;
}

static void setup_display(rays_t *r, textures_t *t, display_t *d, int map_s)
{
    t->line_ht = (map_s * (d->resolution.y / 2)) / r->dist;
    t->step.y = TEXTURES_S / (float)t->line_ht;
    t->offset.y = 0;
    if ((int)t->line_ht > (d->resolution.y / 2)) {
        t->offset.y = (t->line_ht - (d->resolution.y / 2)) / 2;
        t->line_ht = (d->resolution.y / 2);
    }
    t->line_off = (d->resolution.y / 4) - (t->line_ht >> 1);
    return;
}

void display_rc(game_t *g, player_t *p, rays_t *r)
{
    textures_t text = {0};

    r->dist *= cos(deg_to_rad(update_angle(p->angle - r->angle)));
    setup_display(r, &text, &g->settings.display, g->settings.gameplay.map_s);
    draw_walls(r, &text, &g->settings.display);
    draw_fc(p, r, &text, &g->settings.display);
    return;
}
