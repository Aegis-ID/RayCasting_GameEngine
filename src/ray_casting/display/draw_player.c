/*
** EPITECH PROJECT, 2024
** draw_player
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "ray_casting/structs.h"

void draw_player(player_t *p)
{
    //draw p body
    glColor3f(1, 1, 0);
    glPointSize(8);
    glLineWidth(4);
    glBegin(GL_POINTS);
    glVertex2i(p->pos.x, p->pos.y);
    glEnd();
    //draw direction
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(p->pos.x, p->pos.y);
    glVertex2i(p->pos.x + p->delta.x * 20, p->pos.y + p->delta.y * 20);
    glEnd();
}
