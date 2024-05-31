/*
** EPITECH PROJECT, 2024
** display
** File description:
** CSFML
** C'est là que commence la vraie magie noire...
*/

#include <SFML/System.h>
#include <math.h>

#include "lib.h"
#include "game.h"

static void check_v_lines(entity_t *player, map_t *map, ray_t *ray)
{
    float tangent = tan(ray->angle);

    ray->depth_buffer = 0;
    ray->v_dist = 1e30;
    if (cos(ray->angle) > 1e-4) {
        ray->pos.x = (int)player->pos.x / map->height * map->height + map->height;
        ray->pos.y = (player->pos.x - ray->pos.x) * tangent + player->pos.y;
        ray->offset.x = map->height;
        ray->offset.y = -ray->offset.x * tangent;
    } else if (cos(ray->angle) < -1e-4) {
        ray->pos.x = (int)player->pos.x / map->height * map->height - 1e-4;
        ray->pos.y = (player->pos.x - ray->pos.x) * tangent + player->pos.y;
        ray->offset.x = -map->height;
        ray->offset.y = -ray->offset.x * tangent;
    } else {
        ray->pos = player->pos;
        ray->depth_buffer = DEPTH_BUFFER;
    }
    return;
}

static void check_v_collisions(entity_t *player, map_t *map, ray_t *ray)
{
    while (ray->depth_buffer < DEPTH_BUFFER) {
        ray->m_pos.y = (int)ray->pos.y / map->height * map->width
            + (int)ray->pos.x / map->height;
        if ((ray->m_pos.y > 0) && (ray->m_pos.y < map->size) &&
            is_wall(map->walls[ray->m_pos.y])) {
            ray->t_pos.y = map->walls[ray->m_pos.y] - 1;
            ray->v_dist = cos(ray->angle) * (ray->pos.x - player->pos.x)
                -sin(ray->angle) * (ray->pos.y - player->pos.y);
            ray->depth_buffer = DEPTH_BUFFER;
        } else {
            ray->pos.x += ray->offset.x;
            ray->pos.y += ray->offset.y;
            ray->depth_buffer += 1;
        }
    }
    ray->v_pos = ray->pos;
    return;
}

static void check_h_lines(entity_t *player, map_t *map, ray_t *ray)
{
    float atan = 1 / tan(ray->angle);

    ray->depth_buffer = 0;
    ray->h_dist = 1e30;
    if (sin(ray->angle) < -1e-4) {
        ray->pos.y = (int)player->pos.y / map->height * map->width + map->width;
        ray->pos.x = (player->pos.y - ray->pos.y) * atan + player->pos.x;
        ray->offset.y = map->width;
        ray->offset.x = -ray->offset.y * atan;
    } else if (sin(ray->angle) > 1e-4) {
        ray->pos.y = (int)player->pos.y / map->width * map->width - 1e-4;
        ray->pos.x = (player->pos.y - ray->pos.y) * atan + player->pos.x;
        ray->offset.y = -map->width;
        ray->offset.x = -ray->offset.y * atan;
    } else {
        ray->pos = player->pos;
        ray->depth_buffer = DEPTH_BUFFER;
    }
    return;
}

static void check_h_collisions(entity_t *player, map_t *map, ray_t *ray)
{
    while (ray->depth_buffer < DEPTH_BUFFER) {
        ray->m_pos.x = (int)ray->pos.y / map->width * map->width
            + (int)ray->pos.x / map->width;
        if ((ray->m_pos.x > 0) && (ray->m_pos.x < map->size) &&
            is_wall(map->walls[ray->m_pos.x])) {
            ray->t_pos.x = map->walls[ray->m_pos.x] - 1;
            ray->h_dist = cos(ray->angle) * (ray->pos.x - player->pos.x)
                -sin(ray->angle) * (ray->pos.y - player->pos.y);
            ray->depth_buffer = DEPTH_BUFFER;
        } else {
            ray->pos.x += ray->offset.x;
            ray->pos.y += ray->offset.y;
            ray->depth_buffer += 1;
        }
    }
    return;
}

static void get_wall_dist(ray_t *ray)
{
    ray->dist = ray->h_dist;
    ray->t_type = ray->t_pos.x;
    ray->wall_pos = ray->m_pos.x;
    if (ray->v_dist < ray->h_dist) {
        ray->dist = ray->v_dist;
        ray->pos = ray->v_pos;
        ray->t_type = ray->t_pos.y;
        ray->wall_pos = ray->m_pos.y;
    }
    return;
}

void perform_dda(entity_t *player, map_t *map, ray_t *ray)
{
    ray->angle = deg_to_rad(ray->angle);
    check_v_lines(player, map, ray);
    check_v_collisions(player, map, ray);
    check_h_lines(player, map, ray);
    check_h_collisions(player, map, ray);
    get_wall_dist(ray);
    ray->angle = rad_to_deg(ray->angle);
    return;
}

void ray_casting(graphics_t *graphics,
    const entity_t *player, const map_t *map, const float fov)
{
    ray_t *ray = &graphics->ray;
    float world_fov = get_fov(graphics->res, fov);

    ray->angle = get_deg(player->angle + world_fov / 2);
    for (ray->iter = 0; ray->iter < (size_t)graphics->res.x; ++ray->iter) {
        perform_dda(player, map, ray);
        draw_ray(graphics, player, map, fov);
        ray->angle = get_deg(ray->angle - world_fov / graphics->res.x);
    }
    return;
}
