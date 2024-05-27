/*
** EPITECH PROJECT, 2024
** get_collisions.c
** File description:
** CSFML
*/

#include <stdio.h>



static void dist_by_angle(ray_t *ray, collisions_t *col)
{
    if (ray->iter == 0)
        col->back = ray->dist;
    if (ray->iter == 90)
        col->left = ray->dist;
    if (ray->iter == 180) {
        col->front_wall_pos = ray->wall_pos;
        col->front_wall = ray->t_type;
        col->front = ray->dist;
    }
    if (ray->iter == 270)
        col->right = ray->dist;
    return;
}

collisions_t get_collisions(entity_t *p, map_t *m)
{
    collisions_t col = {0};
    ray_t ray = {0};

    ray.angle = get_deg(p->angle + (360 / 2));
    for (ray.iter = 0; (int)ray.iter < 360; ++ray.iter) {
        perform_dda(p, m, &ray);
        get_wall_dist(&ray);
        dist_by_angle(&ray, &col);
        ray.angle = get_deg(ray.angle - 1);
    }
    return col;
}
