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
#include "settings.h"
#include "lib.h"

void draw_walls(player_t *p, maps_t *m, rays_t *r, int r_iter)
{
    int line_height = 0;
    int line_offset = 0;
    int space = 8;

    r->h_dist *= cos(deg_to_rad(update_angle(p->angle - r->angle)));
    line_height = (m->cell_size * (HEIGHT / 2)) / r->h_dist;
    if (line_height > (HEIGHT / 2))
        line_height = (HEIGHT / 2);
    line_offset = (HEIGHT / 4) - (line_height >> 1);

    glLineWidth(space);
    glBegin(GL_LINES);
    glVertex2i(r_iter * space + (WIDTH / 2), line_offset);
    glVertex2i(r_iter * space + (WIDTH / 2), line_height + line_offset);
    glEnd();
    return;
}
