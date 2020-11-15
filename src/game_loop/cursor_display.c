/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** cursor_display
*/

#include "my_hunter.h"

void cursor_display(game_t *game)
{
    cursor_update(game);
    sfSprite_setPosition(CURSOR->skin->sprite, vector2i_to_vector2f(CURSOR->pos));
    sfRenderWindow_drawSprite(CORE->window, CURSOR->skin->sprite, NULL);
}
