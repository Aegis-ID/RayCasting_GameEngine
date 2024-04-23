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
#include "global.h"
#include "lib.h"
#include "settings.h"

float update_angle(float angle)
{
    if (angle >= 360)
        angle -= 360;
    if (angle < 0)
        angle += 360;
    return angle;
}

static void check_v_lines(player_t *p, rays_t *r)
{
    float tangent = tan(deg_to_rad(r->angle));

    r->dof = 0;
    r->v_dist = 100000;
    if (cos(deg_to_rad(r->angle)) > 0.0001) {
        r->pos.x = (((int)p->pos.x / MAP_S) * MAP_S) + MAP_S;
        r->pos.y = (p->pos.x - r->pos.x) * tangent + p->pos.y;
        r->offset.x = MAP_S;
        r->offset.y = -r->offset.x * tangent;
    } else if (cos(deg_to_rad(r->angle)) < -0.0001) {
        r->pos.x = (((int)p->pos.x / MAP_S) * MAP_S) - 0.0001;
        r->pos.y = (p->pos.x - r->pos.x) * tangent + p->pos.y;
        r->offset.x = -MAP_S;
        r->offset.y = -r->offset.x * tangent;
    } else {
        r->pos = p->pos;
        r->dof = DOF;
    }
    return;
}

static void check_v_collisions(player_t *p, maps_t *m, rays_t *r)
{
    while (r->dof < DOF) {
        r->mp = ((int)(r->pos.y) / MAP_S) * m->map_wd + ((int)(r->pos.x) / MAP_S);
        if ((r->mp > 0) && (r->mp < (m->map_ht * m->map_wd)) &&
            m->map[r->mp] > 0) {
            r->dof = DOF;
            r->v_dist = cos(deg_to_rad(r->angle)) * (r->pos.x - p->pos.x)
                -sin(deg_to_rad(r->angle)) * (r->pos.y - p->pos.y);
        } else {
            r->pos.x += r->offset.x;
            r->pos.y += r->offset.y;
            r->dof += 1;
        }
    }
    r->v_pos = r->pos;
    return;
}

static void check_h_lines(player_t *p, rays_t *r)
{
    float tangent = 1 / tan(deg_to_rad(r->angle));

    r->dof = 0;
    r->h_dist = 100000;
    if (sin(deg_to_rad(r->angle)) < -0.0001) {
        r->pos.y = (((int)p->pos.y / MAP_S) * MAP_S) + MAP_S;
        r->pos.x = (p->pos.y - r->pos.y) * tangent + p->pos.x;
        r->offset.y = MAP_S;
        r->offset.x = -r->offset.y * tangent;
    } else if (sin(deg_to_rad(r->angle)) > 0.0001) {
        r->pos.y = (((int)p->pos.y / MAP_S) * MAP_S) - 0.0001;
        r->pos.x = (p->pos.y - r->pos.y) * tangent + p->pos.x;
        r->offset.y = -MAP_S;
        r->offset.x = -r->offset.y * tangent;
    } else {
        r->pos = p->pos;
        r->dof = DOF;
    }
    return;
}

static void check_h_collisions(player_t *p, maps_t *m, rays_t *r)
{
    while (r->dof < DOF) {
        r->mp = ((int)(r->pos.y) / MAP_S) * m->map_wd + ((int)(r->pos.x) / MAP_S);
        if ((r->mp > 0) && (r->mp < (m->map_ht * m->map_wd)) &&
            m->map[r->mp] > 0) {
            r->dof = DOF;
            r->h_dist = cos(deg_to_rad(r->angle)) * (r->pos.x - p->pos.x)
                -sin(deg_to_rad(r->angle)) * (r->pos.y - p->pos.y);
        } else {
            r->pos.x += r->offset.x;
            r->pos.y += r->offset.y;
            r->dof += 1;
        }
    }
    return;
}

static void update_rays(player_t *p, maps_t *m, rays_t *r)
{
    check_v_lines(p, r);
    check_v_collisions(p, m, r);
    check_h_lines(p, r);
    check_h_collisions(p, m, r);
    // ray color
    glColor3f(0.8, 0, 0);
    if (r->v_dist < r->h_dist) {
        glColor3f(0.6, 0, 0);
        r->pos = r->v_pos;
        r->h_dist = r->v_dist;
    }
    return;
}

void ray_casting(player_t *p, maps_t *m)
{
    rays_t r = {0};

    r.angle = update_angle(p->angle + (FOV / 2));
    for (int r_iter = 0; r_iter < FOV; ++r_iter) {
        update_rays(p, m, &r);
        draw_rays(p, &r);
        draw_walls(p, &r, r_iter);
        r.angle = update_angle(r.angle - 1);
    }
    return;
}
