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

static void fix_fisheye(player_t *p, rays_t *r)
{
    float cos_angle = p->angle - r->angle;

    if (cos_angle < 0)
        cos_angle += 2 * M_PI;
    if (cos_angle > 2 * M_PI)
        cos_angle -= 2 * M_PI;
    r->dist *= cos(cos_angle);
    return;
}

void draw3Dwalls(player_t *p, maps_t *m, rays_t *r, int rays)
{
    float line_height = (m->m_size * (HEIGHT / 2)) / r->dist;
    float line_offset = 0;
    int space = 8;

    if (line_height > (HEIGHT / 2))
        line_height = (HEIGHT / 2);
    line_offset = (HEIGHT / 4) - line_height / 2;
    fix_fisheye(p, r);
    glLineWidth(space);
    glBegin(GL_LINES);
    glVertex2i(rays * space + (WIDTH / 2), line_offset);
    glVertex2i(rays * space + (WIDTH / 2), line_height + line_offset);
    glEnd();
    return;
}
