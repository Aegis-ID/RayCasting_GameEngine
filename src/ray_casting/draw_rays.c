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

void draw_rays(player_t *p, rays_t *r)
{
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(p->pos.x, p->pos.y);
    glVertex2i(r->pos.x, r->pos.y);
    glEnd();
    return;
}
