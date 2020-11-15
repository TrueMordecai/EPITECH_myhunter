/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** game_over
*/

#include "my_hunter.h"

bool is_game_over(game_t *game)
{
    if (HUD->timer_str[0] == '0' && HUD->timer_str[1] == '0')
        return (true);
    return (false);
}
