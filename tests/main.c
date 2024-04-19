/*
** EPITECH PROJECT, 2024
** raycasting project
** File description:
** for myrpg
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <math.h>
#include "settings.h"

static void analyze_event(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    else if (event->type == sfEvtResized)
        glViewport(0, 0, event->size.width, event->size.height);
}

int main(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, BITS};
    sfRenderWindow *window = sfRenderWindow_create(mode, NAME, sfDefaultStyle, NULL);
    sfEvent event = {0};
    //initialize main variables here

    sfRenderWindow_setFramerateLimit(window, FRAMES);
    sfRenderWindow_setVerticalSyncEnabled(window, VSYNC);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyze_event(window, &event);
            //do some events here
        }
        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //draw here

        // end the current frame (internally swaps the front and back buffers)
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    //free here
    return 0;
}
