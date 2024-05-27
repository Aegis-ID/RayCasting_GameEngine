/*
** EPITECH PROJECT, 2024
** get_deg
** File description:
** math
*/

float get_deg(float angle)
{
    if (angle >= 360)
        angle -= 360;
    if (angle < 0)
        angle += 360;
    return angle;
}
