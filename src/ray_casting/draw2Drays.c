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
#include "global.h"
#include "settings.h"

void draw2Drays(player_t *p, rays_t *r, sfColor color)
{
    if (r->v_dist < r->h_dist) {
        glColor3f(color.r, color.g, color.b);
    }
    if (r->h_dist < r->v_dist) {
        glColor3f(color.r - 0.4, color.g - 0.4, color.b - 0.4);
    }
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(p->pos.x, p->pos.y);
    glVertex2i(r->pos.x, r->pos.y);
    glEnd();
    return;
}
