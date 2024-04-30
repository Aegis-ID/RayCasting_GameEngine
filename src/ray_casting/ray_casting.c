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
#include "ray_casting/funcs.h"
#include "game/structs.h"
#include "settings/structs.h"

float update_angle(float angle)
{
    if (angle >= 360)
        angle -= 360;
    if (angle < 0)
        angle += 360;
    return angle;
}

static void check_v_lines(player_t *p, rays_t *r, gameplay_t *gp)
{
    float tangent = tan(deg_to_rad(r->angle));

    r->dof = 0;
    r->v_dist = 100000;
    if (cos(deg_to_rad(r->angle)) > 0.0001) {
        r->pos.x = (((int)p->pos.x / gp->map_s) * gp->map_s) + gp->map_s;
        r->pos.y = (p->pos.x - r->pos.x) * tangent + p->pos.y;
        r->offset.x = gp->map_s;
        r->offset.y = -r->offset.x * tangent;
    } else if (cos(deg_to_rad(r->angle)) < -0.0001) {
        r->pos.x = (((int)p->pos.x / gp->map_s) * gp->map_s) - 0.0001;
        r->pos.y = (p->pos.x - r->pos.x) * tangent + p->pos.y;
        r->offset.x = -gp->map_s;
        r->offset.y = -r->offset.x * tangent;
    } else {
        r->pos = p->pos;
        r->dof = DOF;
    }
    return;
}

static void check_v_collisions(player_t *p, maps_t *m, rays_t *r,
    gameplay_t *gp)
{
    while (r->dof < DOF) {
        r->m_pos = ((int)(r->pos.y) / gp->map_s) * m->width
            + ((int)(r->pos.x) / gp->map_s);
        if ((r->m_pos > 0) && (r->m_pos < (m->height * m->width)) &&
            is_wall(m->walls[r->m_pos])) {
            r->w_text_pos.y = m->walls[r->m_pos] - 1;
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

static void check_h_lines(player_t *p, rays_t *r, gameplay_t *gp)
{
    float tangent = 1 / tan(deg_to_rad(r->angle));

    r->dof = 0;
    r->h_dist = 100000;
    if (sin(deg_to_rad(r->angle)) < -0.0001) {
        r->pos.y = (((int)p->pos.y / gp->map_s) * gp->map_s) + gp->map_s;
        r->pos.x = (p->pos.y - r->pos.y) * tangent + p->pos.x;
        r->offset.y = gp->map_s;
        r->offset.x = -r->offset.y * tangent;
    } else if (sin(deg_to_rad(r->angle)) > 0.0001) {
        r->pos.y = (((int)p->pos.y / gp->map_s) * gp->map_s) - 0.0001;
        r->pos.x = (p->pos.y - r->pos.y) * tangent + p->pos.x;
        r->offset.y = -gp->map_s;
        r->offset.x = -r->offset.y * tangent;
    } else {
        r->pos = p->pos;
        r->dof = DOF;
    }
    return;
}

static void check_h_collisions(player_t *p, maps_t *m, rays_t *r,
    gameplay_t *gp)
{
    while (r->dof < DOF) {
        r->m_pos = ((int)(r->pos.y) / gp->map_s) * m->width
            + ((int)(r->pos.x) / gp->map_s);
        if ((r->m_pos > 0) && (r->m_pos < (m->height * m->width)) &&
            is_wall(m->walls[r->m_pos])) {
            r->w_text_pos.x = m->walls[r->m_pos] - 1;
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

static void update_rays(settings_t *s, player_t *p, maps_t *m, rays_t *r)
{
    check_v_lines(p, r, &s->gameplay);
    check_v_collisions(p, m, r, &s->gameplay);
    check_h_lines(p, r, &s->gameplay);
    check_h_collisions(p, m, r, &s->gameplay);
    r->shade = SHADE;
    r->wall_type = r->w_text_pos.x;
    glColor3f(r->shade, r->shade, r->shade);
    if (r->v_dist < r->h_dist) {
        r->wall_type = r->w_text_pos.y;
        r->shade /= 1.75;
        glColor3f(r->shade, r->shade, r->shade);
        r->pos = r->v_pos;
        r->h_dist = r->v_dist;
    }
    return;
}

void ray_casting(game_t *g, player_t *p, maps_t *m)
{
    rays_t rays = {0};
    int fov = g->settings.display.fov;

    rays.wall_type = 0;
    rays.angle = update_angle(p->angle + (fov / 2));
    for (size_t r_iter = 0; (int)r_iter < fov; ++r_iter) {
        rays.r_iter = r_iter;
        update_rays(&g->settings, p, m, &rays);
        draw_rays(p, &rays);
        display_rc(g, p, &rays);
        rays.angle = update_angle(rays.angle - 1);
    }
    return;
}
