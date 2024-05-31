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

bool is_wall(const int m_pos)
{
    if ((m_pos > 0) && (m_pos <= TXR_NB))
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

static float get_text_width(
    const sfVector2u res, const float player_fov, const float deg_angle)
{
    float world_fov = deg_to_rad(get_fov(res, player_fov));
    float ratio = (float)res.x / 2.0f / tan(world_fov / 2.0f);
    float ra_fix = cos(deg_to_rad(deg_angle));

    return ratio / 2 * TXR_S / ra_fix;
}

static void draw_floor(graphics_t *graphics, const entity_t *player, const float fov)
{
    textures_t *txr = &graphics->textures;
    float rad = deg_to_rad(graphics->ray.angle);
    float size =
        get_text_width(graphics->res, fov,
        get_deg(player->angle - graphics->ray.angle));
    float dy = 0;
    int pixel = 0;

    for (txr->iter = txr->offset + txr->height; txr->iter < graphics->res.y; ++txr->iter) {
        dy = txr->iter - ((float)graphics->res.y / 2.0f);
        txr->pos.x = player->pos.x / 2 + cos(rad) * size / dy;
        txr->pos.y = player->pos.y / 2 - sin(rad) * size / dy;
        pixel = ((txr->pos.y & (TXR_S - 1)) * TXR_S + (txr->pos.x & (TXR_S - 1))) * 3;
        set_text_color(pixel, FLOOR_TXR, CONST_SHADE * BRIGHTNESS);
        glPointSize(1);
        glBegin(GL_POINTS);
        glVertex2i(graphics->ray.iter, txr->iter);
        glEnd();
    }
    return;
}

static void draw_vertical_line(
    textures_t *txr, const int iter, const size_t texture_type)
{
    size_t pixel = 0;

    for (int y = 0; y < txr->height; ++y) {
        pixel = (txr->pos.y * TXR_S + txr->pos.x) * 3;
        set_text_color(pixel, ALL_TXR[texture_type], txr->shade);
        glPointSize(1);
        glBegin(GL_POINTS);
        glVertex2i(iter, y + txr->offset);
        glEnd();
        txr->pos.y += txr->step;
    }
    return;
}

static void check_side(const ray_t *ray, textures_t *txr)
{
    if (ray->v_dist >= ray->h_dist) {
        txr->pos.x = (int)(ray->pos.x / 2) % TXR_S;
        if (ray->angle > 180)
            txr->pos.x = (TXR_S - 1) - txr->pos.x;
    } else {
        txr->pos.x = (int)(ray->pos.y / 2) % TXR_S;
        if (ray->angle > 90 && ray->angle < 270)
            txr->pos.x = (TXR_S - 1) - txr->pos.x;
    }
    return;
}

static void setup_textures(textures_t *txr,
    const map_t *map, const ray_t *ray, const sfVector2u res)
{
    txr->shade = (1 / ray->dist * SHADE_DIST) * BRIGHTNESS;
    if (txr->shade > 1)
        txr->shade = 1;
    else if (txr->shade < 0)
        txr->shade = 0;
    txr->height = map->cell_size * res.y / ray->dist;
    txr->step = TXR_S / txr->height;
    if (txr->height > res.y) {
        txr->pos.y = (txr->height - res.y) / 2 * txr->step;
        txr->height = res.y;
    }
    txr->offset = res.y / 2 - (txr->height >> 1);
    return;
}

static void fix_fisheye(ray_t *ray, const float p_angle)
{
    ray->dist *= cos(deg_to_rad(get_deg(p_angle - ray->angle)));
    return;
}

void draw_ray(
    graphics_t *graphics, const entity_t *player, const map_t *map, const float fov)
{
    fix_fisheye(&graphics->ray, player->angle);
    setup_textures(&graphics->textures, map, &graphics->ray, graphics->res);
    check_side(&graphics->ray, &graphics->textures);
    draw_vertical_line(
        &graphics->textures, graphics->ray.iter, graphics->ray.t_type);
    draw_floor(graphics, player, fov);
    return;
}
