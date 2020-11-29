/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** end_round
*/

#include "my_hunter.h"

static void end_round_win_round_reset(game_t *game)
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

static void end_round_win_score_update(game_t *game)
{
    HUD->score[2]++;
    for (int i = 2; i != 0; i--) {
        if (HUD->score[i] == '9' + 1) {
            HUD->score[i - 1]++;
            HUD->score[i] = '0';
        }
    }
}

static void end_round_win_particle_draw(game_t *game)
{
    for (int i = 0; i != PARTICLE_MAX - 1; i++) {
        PARTICLE->pos_tab[i].x += PARTICLE->speed_tab[i].x;
        PARTICLE->pos_tab[i].y += PARTICLE->speed_tab[i].y;
        sfSprite_setPosition(PARTICLE->sprite, PARTICLE->pos_tab[i]);
        sfRenderWindow_drawSprite(CORE->window, PARTICLE->sprite, NULL);
    }
}

static void end_round_win_particle_update(game_t *game)
{
    for (int i = 0; i != PARTICLE_MAX - 1; i++) {
        PARTICLE->speed_tab[i].x -= PARTICLE->speed_tab[i].x / 20;
        PARTICLE->speed_tab[i].y -= PARTICLE->speed_tab[i].y / 20;
    }
    end_round_win_particle_draw(game);
}

void end_round_win(game_t *game)
{
    sfMusic_play(INTRUDER->found_sound);
    sfClock_restart(PARTICLE->clock);
    for (int i = 0; i != PARTICLE_MAX - 1; i++) {
        PARTICLE->speed_tab[i] = speed_randomizer_particle();
        PARTICLE->pos_tab[i] = position_randomizer_particle(INTRUDER);
    }
    while (PARTICLE->seconds < 1.2) {
        sfClock_restart(HUD->timer_clock);
        sfRenderWindow_clear(CORE->window, sfBlack);
        PARTICLE->time = sfClock_getElapsedTime(PARTICLE->clock);
        PARTICLE->seconds = sfTime_asSeconds(PARTICLE->time);
        end_round_win_particle_update(game);
        sfRenderWindow_drawSprite(CORE->window, INTRUDER->sprite, NULL);
        hud_display(game);
        sfRenderWindow_display(CORE->window);
    }
    sfMusic_stop(INTRUDER->found_sound);
    PARTICLE->seconds = 0;
    end_round_win_score_update(game);
    end_round_win_round_reset(game);
}
