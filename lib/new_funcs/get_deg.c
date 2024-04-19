/*
** EPITECH PROJECT, 2024
** get_deg
** File description:
** CSFML
*/

#include <math.h>

float get_degrees(float degrees)
{
	return (float)(fmod(360 + fmod(degrees, 360), 360));
}
