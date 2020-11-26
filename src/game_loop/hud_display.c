/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** hud_display
*/

#include "my_hunter.h"

static void hud_score_display(game_t *game)
{
    sfText_setOutlineColor(HUD->score_text, sfWhite);
    sfText_setColor(HUD->score_text, sfColor_fromRGB(255, 255, 51));
    sfText_setOutlineThickness(HUD->score_text, 1);
    sfText_setString(HUD->score_text, "score =");
    sfText_setPosition(HUD->score_text, vector_create(20, 430));
    sfRenderWindow_drawSprite(CORE->window, game->hud->bground.sprite, NULL);
    sfRenderWindow_drawText(CORE->window, HUD->score_text, NULL);
    sfText_setString(HUD->score_text, HUD->score);
    sfText_setPosition(HUD->score_text, vector_create(335, 430));
    sfRenderWindow_drawText(CORE->window, HUD->score_text, NULL);
}

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

static void hud_timer_update(game_t *game)
{
    HUD->timer_time = sfClock_getElapsedTime(HUD->timer_clock);
    HUD->seconds = sfTime_asSeconds(HUD->timer_time);
    if (HUD->seconds < 1) {
        sfMusic_stop(HUD->bground.found_sound);
        return;
    }
    sfMusic_play(HUD->bground.found_sound);
    HUD->timer_str[1]--;
    for (int i = 1; i != 0; i--) {
        if (HUD->timer_str[i] == '0' - 1) {
            HUD->timer_str[i - 1]--;
            HUD->timer_str[i] = '9';
        }
    }
    sfClock_restart(HUD->timer_clock);
}

static void hud_timer_display(game_t *game)
{
    sfText_setString(HUD->score_text, HUD->timer_str);
    sfText_setPosition(HUD->score_text, vector_create(20, 500));
    if (HUD->timer_str[0] == '0')
        sfText_setColor(HUD->score_text, color_create(200, 70, 10, 255));
    sfRenderWindow_drawText(CORE->window, HUD->score_text, NULL);
    hud_timer_update(game);
}

void hud_display(game_t *game)
{
    hud_score_display(game);
    hud_timer_display(game);
    hud_portrait_display(game);
}
