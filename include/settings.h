/*
** EPITECH PROJECT, 2024
** myrpg
** File description:
** SETTINGS header
*/

#ifndef __SETTINGS__
    #define __SETTINGS__

//Program name (logik)
    #define NAME "Aegis Engine"

//Screen settings (change into struct later, and retrieve info in a config file)
    #define WIDTH 320
    #define HEIGHT 200
    #define BITS 32

    #define FRAMES 60
//If we divide 1 second by 60 frames (60 FPS), the duration of each frame will be 16.667 ms.
    #define FRAME_DURATION 16667;
    #define VSYNC 1

    #define FOV_HORIZONTAL = 90;
    #define FOV_VERTICAL = 58.75;
    #define MOVEMENT_SPEED = 2;

    #define RENDER_DISTANCE = 1024;
    #define STEVEN_ROTATION_SPEED = 2;

//The size of the cell in the game.
    #define CELL_SIZE = 64;

//The size of the cell in the minimap.
    #define MAP_CELL_SIZE = 8;
    #define MAP_GRID_CELL_SIZE = 16;
    #define MAP_HEIGHT = 24;
    #define MAP_WIDTH = 40;
    #define SCREEN_RESIZE = 1;

//Differents types of wall
enum Cell {
	Empty,
	Wall
};

#endif /* !__SETTINGS__ */
