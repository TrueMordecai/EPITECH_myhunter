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
    if (sfKeyboard_isKeyPressed(sfKeyP))
        return (true);
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

void window_event(game_t *game)
{
    sfRenderWindow_pollEvent(CORE->window, &CORE->event);
    if (CORE->event.type  == sfEvtClosed)
        sfRenderWindow_close(CORE->window);
}

int main_loop(void)
{
    game_t *game = game_init();

    if (!game)
        return (0);

    while (sfRenderWindow_isOpen(CORE->window)) {
        window_event(game);
        display_round(game);
        if (is_intruder_click(game))
            end_round_win(game);
        if (is_game_over(game))
            break;
    }
    game_destroy(game);
    return (1);
}
