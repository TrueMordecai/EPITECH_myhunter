/*
** EPITECH PROJECT, 2020
** my_hunte
** File description:
** bounce
*/

#include "my_hunter.h"

static void alt_statue_round_type_entity_update(game_t *game)
{
    for (int i = 0; i != HEAD_MAX - 1; i++) {
        ENTITY->pos.x = 700 + ENTITY->type * 300;
        ENTITY->pos.y = -100;
    }
}

void statue_round_type_entity_update(game_t *game)
{
    if (HUD->round_type_alternative == 1)
        alt_statue_round_type_entity_update(game);
    return;
}
