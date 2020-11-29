/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** init game
*/

#include "my_hunter.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

game_t *game_init(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->hud = hud_init();
    game->core = core_init();
    game->curs = cursor_init();
    game->entity = entity_init();
    game->particle = particle_init();
    return (game);
}
