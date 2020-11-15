/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main loop of my hunter
*/

#include "my_hunter.h"
#include <stdio.h>

void entity_display(game_t *game)
{
    if (game->hud->round_type != STATUE) {
        for (int i = 0; i != HEAD_MAX - 1; i++) {
            sfSprite_setPosition(ENTITY->sprite, ENTITY->pos);
            sfRenderWindow_drawSprite(game->core->window, game->entity[i]->sprite, NULL);
        }
    } else {
        for (int i = 1; i != HEAD_MAX - 1; i++) {
            sfSprite_setPosition(ENTITY->sprite, ENTITY->pos);
            sfRenderWindow_drawSprite(game->core->window, game->entity[i]->sprite, NULL);
        }
        sfSprite_setPosition(INTRUDER->sprite, INTRUDER->pos);
        sfRenderWindow_drawSprite(CORE->window, INTRUDER->sprite, NULL);
    }
}

bool is_intruder_click(game_t *game)
{
    if (!game->curs->is_click)
        return (false);
    if (game->curs->pos.x >= INTRUDER->pos.x && game->curs->pos.x <= INTRUDER->pos.x + (INTRUDER->rect.width * INTRUDER->scale.x))
        if (game->curs->pos.y >= INTRUDER->pos.y && game->curs->pos.y <= INTRUDER->pos.y + (INTRUDER->rect.height * INTRUDER->scale.y))
            return (true);
    return (false);
}

void display_round(game_t *game)
{
    sfRenderWindow_clear(game->core->window, sfBlack);
    round_type_index_select(game);
    entity_display(game);
    hud_display(game);
    cursor_display(game);
    sfRenderWindow_display(game->core->window);
}

void cursor_update(game_t *game)
{
    game->curs->is_click = false;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        game->curs->is_click = true;
    game->curs->pos.x = sfMouse_getPositionRenderWindow(CORE->window).x;
    game->curs->pos.y = sfMouse_getPositionRenderWindow(CORE->window).y;
}

int main_loop(void)
{
    game_t *game = game_init();

    if (!game)
        return (0);
    while (sfKeyboard_isKeyPressed(sfKeyQ) != sfTrue) {
        display_round(game);
        if (is_intruder_click(game))
            end_round_win(game);
        if (is_game_over(game))
            break;
    }
    return (1);
}
