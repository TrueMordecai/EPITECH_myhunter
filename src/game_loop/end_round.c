/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** end_round
*/

#include "my_hunter.h"

static void round_reset(game_t *game)
{
    HUD->round_type = rand() % END_ROUND_TYPE_T;
    HUD->round_type_alternative = rand() % 2;
    INTRUDER->type = rand() % 4;
    INTRUDER->vect = speed_randomizer();
    INTRUDER->pos = position_randomizer(INTRUDER);
    set_entity_rect(INTRUDER);
    set_entity_music(INTRUDER);
    for (int i = 1; i != HEAD_MAX - 1; i++) {
        ENTITY->type = rand() % 4;
        ENTITY->vect = speed_randomizer();
        while (ENTITY->type == INTRUDER->type)
            ENTITY->type = rand() % 4;
        set_entity_rect(ENTITY);
        ENTITY->pos = position_randomizer(ENTITY);
    }
}

static void score_update(game_t *game)
{
    HUD->score[2]++;
    for (int i = 2; i != 0; i--) {
        if (HUD->score[i] == '9' + 1) {
            HUD->score[i - 1]++;
            HUD->score[i] = '0';
        }
    }
}

static void play_sound(game_t *game)
{
    sfMusic_play(INTRUDER->found_sound);
}

void end_round_win(game_t *game)
{
    play_sound(game);
    for (int i = 0; i != 2; i++) {
        sfClock_restart(HUD->timer_clock);
        sfRenderWindow_clear(game->core->window, sfWhite);
        sfRenderWindow_drawSprite(CORE->window, INTRUDER->sprite, NULL);
        hud_display(game);
        sfRenderWindow_display(CORE->window);
        usleep(300000);
        sfRenderWindow_clear(CORE->window, sfBlack);
        sfRenderWindow_drawSprite(CORE->window, INTRUDER->sprite, NULL);
        hud_display(game);
        sfRenderWindow_display(CORE->window);
        usleep(300000);
    }
    score_update(game);
    round_reset(game);
}
