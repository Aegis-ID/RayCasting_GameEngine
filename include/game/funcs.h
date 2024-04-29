/*
** EPITECH PROJECT, 2024
** game
** File description:
** RPG
*/

#ifndef __GAME__
    #define __GAME__

    #include "game/game_structs.h"
    #include "ray_casting/ray_casting_structs.h"

    #define NAME "Aegis Engine"
    #define BITS 64

//inits
game_t init_game(void);
ray_casting_t init_rc_mode(void);

//Main functions
void events(game_t *game, ray_casting_t *rc_mode);
void display(game_t *game, ray_casting_t *rc_mode);

#endif /* !__GAME__ */
