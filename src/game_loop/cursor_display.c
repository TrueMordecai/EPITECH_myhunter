/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** cursor_display
*/

#include "my_hunter.h"

static void cursor_update(game_t *game)
{
    game->curs->is_click = false;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        game->curs->is_click = true;
    game->curs->pos.x = sfMouse_getPositionRenderWindow(CORE->window).x;
    game->curs->pos.y = sfMouse_getPositionRenderWindow(CORE->window).y;
}

void cursor_display(game_t *game)
{
    cursor_update(game);
    sfSprite_setPosition(CURSOR->skin->sprite, vector2i_to_vector2f(CURSOR->pos));
    sfRenderWindow_drawSprite(CORE->window, CURSOR->skin->sprite, NULL);
}
