/*
** EPITECH PROJECT, 2024
** entities_CONSTS
** File description:
** CSFML
*/

#ifndef __ENTITIES_CONSTS__
    #define __ENTITIES_CONSTS__

    #include <stddef.h>

const char *SPRITE_SHEETS[] = {
    "assets/entities/skeleton.png",
    "assets/entities/bear.png",
    "assets/entities/troll.png",
    "assets/entities/spider.png",
    "assets/entities/slime.png",
    NULL,
};

const char *R_HAND_FRAMES[] = {
    "assets/sword/0.png",
    "assets/sword/1.png",
    "assets/sword/2.png",
    "assets/sword/3.png",
    "assets/sword/4.png",
    NULL,
};

const char *SKELETON_IDLE_FRAMES[] = {
    "assets/entities/skeleton/idle0.png",
    "assets/entities/skeleton/idle1.png",
    NULL,
};

const char *SKELETON_WALK_FRAMES[] = {
    "assets/entities/skeleton/walk0.png",
    "assets/entities/skeleton/walk1.png",
    NULL,
};

const char *SKELETON_ATTACK_FRAMES[] = {
    "assets/entities/skeleton/attack0.png",
    "assets/entities/skeleton/attack1.png",
    NULL,
};

const char *SKELETON_HIT_FRAMES[] = {
    "assets/entities/skeleton/hit0.png",
    "assets/entities/skeleton/hit1.png",
    NULL,
};

const char *SKELETON_DEATH_FRAMES[] = {
    "assets/entities/skeleton/death0.png",
    "assets/entities/skeleton/death1.png",
    NULL,
};

#endif
