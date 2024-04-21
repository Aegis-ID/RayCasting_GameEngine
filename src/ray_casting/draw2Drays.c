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
#include <string.h>
#include <math.h>
#include "global.h"
#include "lib.h"
#include "window.h"

#define M_PI_3 3 * M_PI / 2

static void draw_rays(player_t *player, rays_t *rays, sfColor color)
{
    glColor3f(color.r, color.g, color.b);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(player->pos.x, player->pos.y);
    glVertex2i(rays->pos.x, rays->pos.y);
    glEnd();
    return;
}

static void check_collisions(player_t *player, maps_t *map, rays_t *rays, sfColor color)
{
    size_t mp = 0;
    int my = 0;
    int mx = 0;

    while (rays->dof < DOF) {
        my = (int)(rays->pos.y) >> 6;
        mx = (int)(rays->pos.x) >> 6;
        mp = my * map->m_width + mx;
        if ((mp > 0) && (mp < map->m_size) && is_wall(map->map[mp])) {
            rays->dof = DOF;
        } else {
            rays->pos.x += rays->offset.x;
            rays->pos.y += rays->offset.y;
            rays->dof += 1;
        }
    }
    return draw_rays(player, rays, color);
}

static void check_h_lines(player_t *p, maps_t *map, rays_t *r, sfColor color)
{
    float aTan = -1 / tan(r->angle);

    if (r->angle > M_PI) {
        r->pos.y = (((int)p->pos.y >> 6) << 6) - 0.0001;       //round r Y position to the nearest 64th value by bitshifting
        r->pos.x = (p->pos.y - r->pos.y) * aTan + p->pos.x;
        r->offset.y = -64;
        r->offset.x = -r->offset.y * aTan;
    }
    if (r->angle < M_PI) {
        r->pos.y = (((int)p->pos.y >> 6) << 6) + 64;
        r->pos.x = (p->pos.y - r->pos.y) * aTan + p->pos.x;
        r->offset.y = 64;
        r->offset.x = -r->offset.y * aTan;
    }
    if ((r->angle == 0) || (r->angle == M_PI)) {
        r->pos.y = p->pos.y;
        r->pos.x = p->pos.x;
        r->dof = DOF;
    }
    return check_collisions(p, map, r, color);
}

static void check_v_lines(player_t *player, maps_t *map, rays_t *rays, sfColor color)
{
    float nTan = -tan(rays->angle);

    if ((rays->angle > M_PI_2) && (rays->angle < M_PI_3)) {
        rays->pos.x = (((int)player->pos.x >> 6) << 6) - 0.0001;       //round rays X position to the nearest 64th value by bitshifting
        rays->pos.y = (player->pos.x - rays->pos.x) * nTan + player->pos.y;
        rays->offset.x = -64;
        rays->offset.y = -rays->offset.x * nTan;
    }
    if ((rays->angle < M_PI_2) || (rays->angle > M_PI_3)) {
        rays->pos.x = (((int)player->pos.x >> 6) << 6) + 64;
        rays->pos.y = (player->pos.x - rays->pos.x) * nTan + player->pos.y;
        rays->offset.x = 64;
        rays->offset.y = -rays->offset.x * nTan;
    }
    if ((rays->angle == 0) || (rays->angle == M_PI)) {
        rays->pos.y = player->pos.y;
        rays->pos.x = player->pos.x;
        rays->dof = DOF;
    }
    return check_collisions(player, map, rays, color);
}

void draw2Drays(player_t *player, maps_t *map)
{
    rays_t rays = {0};

    rays.angle = player->angle;
    for (int r = 0; r < FOV; ++r) {
        rays.dof = 0;
        check_h_lines(player, map, &rays, sfColor_fromRGB(0, 1, 0));
        check_v_lines(player, map, &rays, sfColor_fromRGB(1, 0, 0));
    }
    return;
}
