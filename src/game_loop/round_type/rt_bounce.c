/*
** EPITECH PROJECT, 2020
** my_hunte
** File description:
** bounce
*/

#include "my_hunter.h"

void bounce_round_type_entity_update_alternative(game_t *game)
{
    for (int i = 0; i != HEAD_MAX - 1; i++) {
        ENTITY->pos.x += ENTITY->vect.x;
        ENTITY->pos.y += ENTITY->vect.y;
        if (ENTITY->pos.y <= 0 || rand() % 200 == 0)
            ENTITY->vect.y *= -1;
        if (ENTITY->pos.y + (ENTITY->rect.height * ENTITY->scale.y) >= 1060)
            ENTITY->vect.y *= -1;
        if (ENTITY->pos.x <= 500 || rand() % 200 == 0)
            ENTITY->vect.x *= -1;
        if (ENTITY->pos.x + (ENTITY->rect.width * ENTITY->scale.x) >= 1920)
            ENTITY->vect.x *= -1;
    }
}

void bounce_round_type_entity_update(game_t *game)
{
    if (game->hud->round_type_alternative) {
        bounce_round_type_entity_update_alternative(game);
        return;
    }
    for (int i = 0; i != HEAD_MAX - 1; i++) {
        ENTITY->pos.x += ENTITY->vect.x;
        ENTITY->pos.y += ENTITY->vect.y;
        if (ENTITY->pos.y <= 0)
            ENTITY->vect.y *= -1;
        if (ENTITY->pos.y + (ENTITY->rect.height * ENTITY->scale.y) >= 1060)
            ENTITY->vect.y *= -1;
        if (ENTITY->pos.x <= 500)
            ENTITY->vect.x *= -1;
        if (ENTITY->pos.x + (ENTITY->rect.width * ENTITY->scale.x) >= 1920)
            ENTITY->vect.x *= -1;
    }
}
