/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** destroy game
*/

#include "my_hunter.h"

void destroy_entity(entity_t *entity, char *to_destroy)
{
    if (my_strlen(to_destroy) != 3 || to_destroy == NULL) {
        sfTexture_destroy(entity->texture);
        sfSprite_destroy(entity->sprite);
        sfMusic_destroy(entity->found_sound);
    }
    if (to_destroy[0] == '1')
        sfSprite_destroy(entity->sprite);
    if (to_destroy[1] == '1')
        sfTexture_destroy(entity->texture);
    if (to_destroy[2] == '1')
        sfMusic_destroy(entity->found_sound);
}

void destroy_hud(hud_t *hud)
{
    destroy_entity(&hud->bground, "110");
    destroy_entity(&hud->portrait[0], "110");
    sfText_destroy(hud->score_text);
    sfClock_destroy(hud->timer_clock);
    free(hud);
}

void game_destroy(game_t *game)
{
    destroy_hud(game->hud);
    sfRenderWindow_destroy(game->core->window);
    free(game->core);
    destroy_entity(INTRUDER, "101");
    for (int i = 1; i != HEAD_MAX - 1; i++) {
        destroy_entity(ENTITY, "101");
        free (ENTITY);
    }
    free(game->entity);
    destroy_entity(game->curs->skin, "110");
    free(game->curs);
    free(game);
}
