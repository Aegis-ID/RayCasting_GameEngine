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

typedef struct vector_s {
    float x;
    float y;
} vector_t;

typedef struct player_s {
    vector_t pos;
} player_t;



static void buttons(sfEvent *event, vector_t *player_pos)
{
    if (event->key.code == sfKeyQ)
        player_pos->x -= 5;
    if (event->key.code == sfKeyD)
        player_pos->x += 5;
    if (event->key.code == sfKeyZ)
        player_pos->y -= 5;
    if (event->key.code == sfKeyS)
        player_pos->y += 5;
}

void drawPlayer(vector_t *player_pos)
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(player_pos->x, player_pos->y);
    glEnd();
}

void display(sfRenderWindow *window, player_t *player)
{
    // clear the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //draw here
    drawPlayer(&player->pos);
    /* // end the current frame (internally swaps the front and back buffers) */
    sfRenderWindow_display(window);
}

void init(sfRenderWindow *window, player_t *player)
{
    sfRenderWindow_setFramerateLimit(window, FRAMES);
    sfRenderWindow_setVerticalSyncEnabled(window, VSYNC);

    glClearColor(0.3, 0.3, 0.3, 0);
    player->pos.x = 300;
    player->pos.y = 300;
}

static void events(sfRenderWindow *window, sfEvent *event, player_t *player)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    else if (event->type == sfEvtResized)
        glViewport(0, 0, event->size.width, event->size.height);
    buttons(event, &player->pos);
}

int main(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, BITS};
    sfRenderWindow *window = sfRenderWindow_create(mode, NAME, sfDefaultStyle, NULL);
    sfEvent event = {0};
    //init here
    player_t player;

    init(window, &player);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            //do events here
            events(window, &event, &player);
        }
        //display here
        display(window, &player);
        printf("x: %f -- y: %f\n", player.pos.x, player.pos.y);
    }
    //free here
    sfRenderWindow_destroy(window);
    return 0;
}
