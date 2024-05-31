/*
** EPITECH PROJECT, 2024
** draw_sky
** File description:
** CSFML
*/

#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <stddef.h>

#include "../assets/textures/SKY_TXR.ppm"

static void update_offset(int *offset, const sfVector2u sky)
{
    if (*offset < 0)
        *offset += sky.x;
    *offset %= sky.x;
    return;
}

void draw_sky(const sfVector2u res, const float p_angle, const float shade)
{
    sfVector2u sky = {120, 60};
    size_t pixel = 0;
    int pixel_s = res.x / sky.x + 1;
    int offset = 0;

    for (size_t y = 0; y < sky.y; ++y) {
        for (size_t x = 0; x < sky.x; ++x) {
            offset = p_angle - x;
            update_offset(&offset, sky);
            pixel = (y * sky.x + offset) * 3;
            set_text_color(pixel, SKY_TXR, shade);
            glPointSize(pixel_s);
            glBegin(GL_POINTS);
            glVertex2i(x * pixel_s, y * pixel_s);
            glEnd();
        }
    }
    return;
}
