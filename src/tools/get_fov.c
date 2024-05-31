/*
** EPITECH PROJECT, 2024
** get_fov
** File description:
** MATHS
*/

#include <SFML/Graphics.h>

#include "lib.h"

float get_fov(const sfVector2u res, const float default_fov)
{
    float fov = 2 * deg_to_rad(default_fov / 2) * get_ratio(res);

    return rad_to_deg(fov);
}
