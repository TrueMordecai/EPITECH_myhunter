/*
** EPITECH PROJECT, 2020
** my_hunte
** File description:
** bounce
*/

#include "my_hunter.h"

void ghost_round_type_entity_update(game_t *game)
{
    for (int i = 0; i != HEAD_MAX - 1; i++) {
        ENTITY->pos.x += ENTITY->vect.x;
        ENTITY->pos.y += ENTITY->vect.y;
        if (ENTITY->pos.y < -300)
            ENTITY->pos.y = 1080;
        if (ENTITY->pos.y >= 1100)
            ENTITY->pos.y = -250;
        if (ENTITY->pos.x <= 200)
            ENTITY->pos.x = 1920;
        if (ENTITY->pos.x >= 2050)
            ENTITY->pos.x = 230;
    }
}
