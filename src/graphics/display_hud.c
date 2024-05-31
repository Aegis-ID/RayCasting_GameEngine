/*
** EPITECH PROJECT, 2024
** interactions_display
** File description:
** CSFML
*/

#include "game.h"

#include "entities.h"

static bool is_anim_over(entity_t *entity)
{
    if (entity->current_frame == entity->nb_frames - 1)
        return true;
    return false;
}

/*
static void right_hand_display(sfRenderWindow *window,
    entity_t *r_hand, gameplay_t *gameplay, sfVector2u res)
{
    sfSprite *sprite = r_hand->sprite;
    sfFloatRect global = sfSprite_getGlobalBounds(sprite);

    set_scale(sprite, res.y / global.height);
    global = sfSprite_getGlobalBounds(sprite);
    set_pos(sprite, res.x - global.width / 2, res.y - global.height / 2);
    if (gameplay->r_hand)
        animate(window, r_hand, R_HAND_FPS);
    else {
        sfSprite_setTexture(
            r_hand->sprite, r_hand->textures[0], sfTrue);
        sfRenderWindow_drawSprite(window, r_hand->sprite, NULL);
    }
    if (is_anim_over(r_hand))
        gameplay->r_hand = false;
    return;
}
 */

void display_exploration_hud(game_t *game)
{
    entity_t *entities = game->entities;
    gameplay_t *gameplay = &game->gameplay;
    sfVector2u res = game->settings.display.res;

//    right_hand_display(game->window, &entities[R_HAND], gameplay, res);
    return;
}
