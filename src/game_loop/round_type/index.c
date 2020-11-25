/*
** EPITECH PROJECT, 2020
** my_hunte
** File description:
** bounce
*/

#include "my_hunter.h"

bool round_type_index_select_is_clock_check(game_t *game)
{
    CORE->mvmt_time = sfClock_getElapsedTime(CORE->mvmt_clock);
    CORE->mvmt_seconds = sfTime_asSeconds(CORE->mvmt_time);
    if (CORE->mvmt_seconds >= 1 / 60) {
        sfClock_restart(CORE->mvmt_clock);
        CORE->mvmt_seconds = 0;
        return (true);
    }
    return (false);
}

void round_type_index_select(game_t *game)
{
    if (!round_type_index_select_is_clock_check(game))
        return;
    if (game->hud->round_type == GHOST)
        ghost_round_type_entity_update(game);
    if (game->hud->round_type == BOUNCE)
        bounce_round_type_entity_update(game);
    if (game->hud->round_type == STATUE)
        statue_round_type_entity_update(game);
}
