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
#include "settings.h"

static void check_v_lines(entity_t *p, map_t *m, ray_t *r)
{
    float tangent = tan(r->angle);

    r->depth_buffer = 0;
    r->v_dist = 1e30;
    if (cos(r->angle) > 1e-4) {
        r->pos.x = (int)p->pos.x / m->height * m->height + m->height;
        r->pos.y = (p->pos.x - r->pos.x) * tangent + p->pos.y;
        r->offset.x = m->height;
        r->offset.y = -r->offset.x * tangent;
    } else if (cos(r->angle) < -1e-4) {
        r->pos.x = (int)p->pos.x / m->height * m->height - 1e-4;
        r->pos.y = (p->pos.x - r->pos.x) * tangent + p->pos.y;
        r->offset.x = -m->height;
        r->offset.y = -r->offset.x * tangent;
    } else {
        r->pos = p->pos;
        r->depth_buffer = DEPTH_BUFFER;
    }
    return;
}

static void check_v_collisions(entity_t *p, map_t *m, ray_t *r)
{
    while (r->depth_buffer < DEPTH_BUFFER) {
        r->m_pos.y = (int)r->pos.y / m->height * m->width
            + (int)r->pos.x / m->height;
        if ((r->m_pos.y > 0) && (r->m_pos.y < m->size) &&
            is_wall(m->walls[r->m_pos.y])) {
            r->t_pos.y = m->walls[r->m_pos.y] - 1;
            r->v_dist = cos(r->angle) * (r->pos.x - p->pos.x)
                -sin(r->angle) * (r->pos.y - p->pos.y);
            r->depth_buffer = DEPTH_BUFFER;
        } else {
            r->pos.x += r->offset.x;
            r->pos.y += r->offset.y;
            r->depth_buffer += 1;
        }
    }
    r->v_pos = r->pos;
    return;
}

static void check_h_lines(entity_t *p, map_t *m, ray_t *r)
{
    float atan = 1 / tan(r->angle);

    r->depth_buffer = 0;
    r->h_dist = 1e30;
    if (sin(r->angle) < -1e-4) {
        r->pos.y = (int)p->pos.y / m->height * m->width + m->width;
        r->pos.x = (p->pos.y - r->pos.y) * atan + p->pos.x;
        r->offset.y = m->width;
        r->offset.x = -r->offset.y * atan;
    } else if (sin(r->angle) > 1e-4) {
        r->pos.y = (int)p->pos.y / m->width * m->width - 1e-4;
        r->pos.x = (p->pos.y - r->pos.y) * atan + p->pos.x;
        r->offset.y = -m->width;
        r->offset.x = -r->offset.y * atan;
    } else {
        r->pos = p->pos;
        r->depth_buffer = DEPTH_BUFFER;
    }
    return;
}

static void check_h_collisions(entity_t *p, map_t *m, ray_t *r)
{
    while (r->depth_buffer < DEPTH_BUFFER) {
        r->m_pos.x = (int)r->pos.y / m->width * m->width
            + (int)r->pos.x / m->width;
        if ((r->m_pos.x > 0) && (r->m_pos.x < m->size) &&
            is_wall(m->walls[r->m_pos.x])) {
            r->t_pos.x = m->walls[r->m_pos.x] - 1;
            r->h_dist = cos(r->angle) * (r->pos.x - p->pos.x)
                -sin(r->angle) * (r->pos.y - p->pos.y);
            r->depth_buffer = DEPTH_BUFFER;
        } else {
            r->pos.x += r->offset.x;
            r->pos.y += r->offset.y;
            r->depth_buffer += 1;
        }
    }
    return;
}

static void get_wall_dist(ray_t *r)
{
    r->dist = r->h_dist;
    r->t_type = r->t_pos.x;
    r->wall_pos = r->m_pos.x;
    if (r->v_dist < r->h_dist) {
        r->dist = r->v_dist;
        r->pos = r->v_pos;
        r->t_type = r->t_pos.y;
        r->wall_pos = r->m_pos.y;
    }
    return;
}

void perform_dda(entity_t *p, map_t *m, ray_t *r)
{
    r->angle = deg_to_rad(r->angle);
    check_v_lines(p, m, r);
    check_v_collisions(p, m, r);
    check_h_lines(p, m, r);
    check_h_collisions(p, m, r);
    get_wall_dist(r);
    r->angle = rad_to_deg(r->angle);
    return;
}

void ray_casting(graphics_t *rays, const sfVector2i res, const float fov)
{
    entity_t *p = &rays->player;
    map_t *m = &rays->map;
    ray_t *r = &rays->ray;
    float world_fov = get_fov(res, fov);

    r->fov = fov;
    r->angle = get_deg(p->angle + world_fov / 2);
    for (r->iter = 0; (int)r->iter < res.x; ++r->iter) {
        perform_dda(p, m, r);
        r->dist *= cos(deg_to_rad(get_deg(p->angle - r->angle)));
        draw_ray(rays, res);
        r->angle = get_deg(r->angle - world_fov / res.x);
    }
    return;
}
