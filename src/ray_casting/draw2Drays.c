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

static void draw_rays(player_t *player, rays_t *rays)
{
    glColor3f(0, 1, 0);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(player->pos.x, player->pos.y);
    glVertex2i(rays->r_pos.x, rays->r_pos.y);
    glEnd();
    return;
}

static sfBool is_wall(int cell)
{
    if (cell == 1)
        return sfTrue;
    return sfFalse;
}

static void check_collisions(maps_t *map, rays_t *rays)
{
    size_t mp = 0;

    while (rays->dof < DOF) {
        rays->m_pos.y = (int)(rays->r_pos.y) >> 6;
        rays->m_pos.x = (int)(rays->r_pos.x) >> 6;
        mp = rays->m_pos.y * map->m_width + rays->m_pos.x;
        if (mp < map->m_size && is_wall(map->map[mp])) {
            rays->dof = 8;
        } else {
            rays->r_pos.x += rays->offset.x;
            rays->r_pos.y += rays->offset.y;
            rays->dof += 1;
        }
    }
    return;
}

static void check_h_lines(player_t *player, rays_t *rays, float aTan)
{
    if (rays->angle > M_PI) {
        //round rays Y position to the nearest 64th value by bitshifting
        rays->r_pos.y = (((int)player->pos.y >> 6) << 6) - 0.0001;
        rays->r_pos.x = (player->pos.y - rays->r_pos.y) * aTan + player->pos.x;
        rays->offset.y = -64;
        rays->offset.x = -rays->offset.y * aTan;
    }
    if (rays->angle < M_PI) {
        rays->r_pos.y = (((int)player->pos.y >> 6) << 6) + 64;
        rays->r_pos.x = (player->pos.y - rays->r_pos.y) * aTan + player->pos.x;
        rays->offset.y = 64;
        rays->offset.x = -rays->offset.y * aTan;
    }
    if ((rays->angle == 0) || (rays->angle == M_PI)) {
        rays->r_pos.y = player->pos.y;
        rays->r_pos.x = player->pos.x;
        rays->dof = DOF;
    }
    return;
}

void draw2Drays(player_t *player, maps_t *map)
{
    rays_t rays = {0};
    float aTan = 0;

    rays.angle = player->angle;
    aTan = -1 / tan(rays.angle);
    for (int r = 0; r < FOV; ++r) {
        check_h_lines(player, &rays, aTan);
        check_collisions(map, &rays);
        draw_rays(player, &rays);
    }
    return;
}
