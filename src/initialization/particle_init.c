/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** entity_init.c
*/

#include "my_hunter.h"

particle_t *particle_init(void)
{
    particle_t *particle = malloc(sizeof(particle_t));

    particle->sprite = sfSprite_create();
    particle->texture = sfTexture_createFromFile("image/star.png", NULL);
    sfSprite_setScale(particle->sprite, vector_create(0.5, 0.5));
    sfSprite_setTexture(particle->sprite, particle->texture, sfTrue);
    particle->speed_tab = malloc(sizeof(sfVector2f) * PARTICLE_MAX);
    particle->pos_tab = malloc(sizeof(sfVector2f) * PARTICLE_MAX);
    particle->clock = sfClock_create();
    particle->time = sfTime_Zero;
    particle->seconds = 0;
    for(int i = 0; i != PARTICLE_MAX - 1; i++)
        particle->speed_tab[i] = speed_randomizer();
    return (particle);
}
