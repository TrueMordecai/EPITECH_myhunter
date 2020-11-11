/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** hud_display
*/

#include "my_hunter.h"

static void hud_portrait_display(game_t *game)
{
    if (INTRUDER_TYPE == LUIGI) {
        game->hud->portrait->rect = rect_create(0, 0, 61, 48);
        sfSprite_setPosition(HUD->portrait->sprite, vector_create(215, 110));
    }
    if (INTRUDER_TYPE == MARIO) {
        game->hud->portrait->rect = rect_create(0, 48, 61, 48);
        sfSprite_setPosition(HUD->portrait->sprite, vector_create(215, 110));
    }
    if (INTRUDER_TYPE == YOSHI) {
        game->hud->portrait->rect = rect_create(0, 96, 61, 48);
        sfSprite_setPosition(HUD->portrait->sprite, vector_create(215, 110));
    }
    if (INTRUDER_TYPE == WARIO) {
        game->hud->portrait->rect = rect_create(0, 144, 61, 55);
        sfSprite_setPosition(HUD->portrait->sprite, vector_create(203, 110));
    }
    sfSprite_setTextureRect(HUD->portrait->sprite, HUD->portrait->rect);
    sfRenderWindow_drawSprite(CORE->window, HUD->portrait->sprite, NULL);
}

void hud_display(game_t *game)
{
    sfText_setString(HUD->score_text, "score =");
    sfText_setPosition(HUD->score_text, vector_create(20, 430));
    sfRenderWindow_drawSprite(CORE->window, game->hud->bground.sprite, NULL);
    sfRenderWindow_drawText(CORE->window, HUD->score_text, NULL);
    sfText_setString(HUD->score_text, HUD->score);
    sfText_setPosition(HUD->score_text, vector_create(335, 430));
    sfRenderWindow_drawText(CORE->window, HUD->score_text, NULL);
    hud_portrait_display(game);
}
