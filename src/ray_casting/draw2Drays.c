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

static float pythagoras(sfVector2f a, sfVector2f b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

static void draw_rays(player_t *p, rays_t *r, sfColor color)
{
    if (r->v_dist < r->h_dist)
        r->pos = r->v_pos;
    if (r->h_dist < r->v_dist)
        r->pos = r->h_pos;
    glColor3f(color.r, color.g, color.b);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(p->pos.x, p->pos.y);
    glVertex2i(r->pos.x, r->pos.y);
    glEnd();
    return;
}

static void check_h_collisions(player_t *p, maps_t *m, rays_t *r)
{
    while (r->dof < DOF) {
        r->mp = ((int)(r->pos.y) >> 6) * m->m_width + ((int)(r->pos.x) >> 6);
        if ((r->mp > 0) && (r->mp < m->m_size) && is_wall(m->map[r->mp])) {
            r->dof = DOF;
            r->h_pos = r->pos;
            r->h_dist = pythagoras(p->pos, r->h_pos);
        } else {
            r->pos.x += r->offset.x;
            r->pos.y += r->offset.y;
            r->dof += 1;
        }
    }
    return;
}

static void check_v_collisions(player_t *p, maps_t *m, rays_t *r)
{
    while (r->dof < DOF) {
        r->mp = ((int)(r->pos.y) >> 6) * m->m_width + ((int)(r->pos.x) >> 6);
        if ((r->mp > 0) && (r->mp < m->m_size) && is_wall(m->map[r->mp])) {
            r->dof = DOF;
            r->v_pos = r->pos;
            r->v_dist = pythagoras(p->pos, r->v_pos);
        } else {
            r->pos.x += r->offset.x;
            r->pos.y += r->offset.y;
            r->dof += 1;
        }
    }
    return;
}

static void reset_check(int *dof, float *dist,
    sfVector2f *pos, sfVector2f p_pos)
{
    *dof = 0;
    *dist = 1000000;
    *pos = p_pos;
}

static void check_h_lines(player_t *p, rays_t *r)
{
    float aTan = -1 / tan(r->angle);

    reset_check(&r->dof, &r->h_dist, &r->h_pos, p->pos);
    if (r->angle > M_PI) {
        r->pos.y = (((int)p->pos.y >> 6) << 6) - 0.0001;
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
        r->pos = p->pos;
        r->dof = DOF;
    }
    return;
}

static void check_v_lines(player_t *p, rays_t *r)
{
    float nTan = -tan(r->angle);

    reset_check(&r->dof, &r->v_dist, &r->v_pos, p->pos);
    if ((r->angle > M_PI_2) && (r->angle < M_PI_3)) {
        r->pos.x = (((int)p->pos.x >> 6) << 6) - 0.0001;
        r->pos.y = (p->pos.x - r->pos.x) * nTan + p->pos.y;
        r->offset.x = -64;
        r->offset.y = -r->offset.x * nTan;
    }
    if ((r->angle < M_PI_2) || (r->angle > M_PI_3)) {
        r->pos.x = (((int)p->pos.x >> 6) << 6) + 64;
        r->pos.y = (p->pos.x - r->pos.x) * nTan + p->pos.y;
        r->offset.x = 64;
        r->offset.y = -r->offset.x * nTan;
    }
    if ((r->angle == 0) || (r->angle == M_PI)) {
        r->pos = p->pos;
        r->dof = DOF;
    }
    return;
}

void draw2Drays(player_t *p, maps_t *m)
{
    rays_t r = {0};

    r.angle = p->angle;
    for (int rays = 0; rays < FOV; ++rays) {
        check_h_lines(p, &r);
        check_h_collisions(p, m, &r);
        check_v_lines(p, &r);
        check_v_collisions(p, m, &r);
        draw_rays(p, &r, sfColor_fromRGB(1, 0, 0));
    }
    return;
}
