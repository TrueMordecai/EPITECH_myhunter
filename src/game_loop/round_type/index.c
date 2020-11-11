/*
** EPITECH PROJECT, 2020
** my_hunte
** File description:
** bounce
*/

#include "my_hunter.h"

void round_type_index_select(game_t *game)
{
    if (game->hud->round_type == GHOST)
        ghost_round_type_entity_update(game);
    if (game->hud->round_type == BOUNCE)
        bounce_round_type_entity_update(game);
    if (game->hud->round_type == STATUE)
        statue_round_type_entity_update(game);
}
