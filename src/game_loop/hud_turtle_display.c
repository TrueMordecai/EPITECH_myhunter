/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** hud_turtle_display
*/

#include "my_hunter.h"

static bool hud_turtle_display_float_comparison(float s, float a, float b)
{
    if (s > a && s <= b)
        return (true);
    return (false);
}

static void hud_turtle_display_animate1(game_t *game)
{
    HUD->turtle.time = sfClock_getElapsedTime(HUD->turtle.clock);
    HUD->turtle.seconds = sfTime_asSeconds(HUD->turtle.time);
    if (hud_turtle_display_float_comparison(HUD->turtle.seconds, 0, 0.1))
        HUD->turtle.rect = rect_create(0, 0, 17, 16);
    if (hud_turtle_display_float_comparison(HUD->turtle.seconds, 0.1, 0.2))
        HUD->turtle.rect = rect_create(0, 20, 17, 16);
    if (hud_turtle_display_float_comparison(HUD->turtle.seconds, 0.2, 0.3))
        HUD->turtle.rect = rect_create(0, 40, 17, 16);
    if (hud_turtle_display_float_comparison(HUD->turtle.seconds, 0.3, 0.4))
        HUD->turtle.rect = rect_create(0, 60, 17, 16);
    if (hud_turtle_display_float_comparison(HUD->turtle.seconds, 0.4, 0.5))
        HUD->turtle.rect = rect_create(0, 80, 17, 16);
    if (hud_turtle_display_float_comparison(HUD->turtle.seconds, 0.5, 0.6))
        HUD->turtle.rect = rect_create(0, 100, 17, 16);
    if (hud_turtle_display_float_comparison(HUD->turtle.seconds, 0.6, 0.7))
        HUD->turtle.rect = rect_create(0, 120, 17, 16);
    if (hud_turtle_display_float_comparison(HUD->turtle.seconds, 0.7, 0.8))
        HUD->turtle.rect = rect_create(0, 140, 17, 16);
    if (hud_turtle_display_float_comparison(HUD->turtle.seconds, 0.8, 0.9))
        HUD->turtle.rect = rect_create(0, 160, 17, 16);
}

void hud_turtle_display(game_t *game)
{
    hud_turtle_display_animate1(game);
    if (HUD->turtle.seconds >= 0.9) {
        HUD->turtle.seconds = 0;
        sfClock_restart(HUD->turtle.clock);
    }
    sfSprite_setTextureRect(HUD->turtle.sprite, HUD->turtle.rect);
    sfRenderWindow_drawSprite(CORE->window, HUD->turtle.sprite, NULL);
}
