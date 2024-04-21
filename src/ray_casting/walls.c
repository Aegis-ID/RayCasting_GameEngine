/*
** EPITECH PROJECT, 2024
** display
** File description:
** Wall definitions
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>

void colorize_cell(int cell)
{
    if (cell == 1)
        glColor3f(1, 1, 1);
    else
        glColor3f(0, 0, 0);
}

sfBool is_wall(int cell)
{
    if (cell == 1)
        return sfTrue;
    return sfFalse;
}
