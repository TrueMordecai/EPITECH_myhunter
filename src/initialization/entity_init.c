/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** entity_init.c
*/

#include "my_hunter.h"

void set_entity_music(entity_t *entity)
{
    if (entity->type == MARIO)
        entity->found_sound = sfMusic_createFromFile("sound/mario_found.wav");
    if (entity->type == LUIGI)
        entity->found_sound = sfMusic_createFromFile("sound/luigi_found.wav");
    if (entity->type == WARIO)
        entity->found_sound = sfMusic_createFromFile("sound/wario_found.wav");
    if (entity->type == YOSHI)
        entity->found_sound = sfMusic_createFromFile("sound/yoshi_found.wav");
}

static entity_t *intruder_init(sfTexture *texture)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->sprite = sfSprite_create();
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->type = rand() % 4;
    entity->scale = vector_create(4, 4);
    sfSprite_setScale(entity->sprite, entity->scale);
    entity->vect = speed_randomizer();
    set_entity_rect(entity);
    entity->pos = position_randomizer(entity);
    sfSprite_setPosition(entity->sprite, entity->pos);
    set_entity_music(entity);
    return (entity);
}

entity_t **entity_init(void)
{
    entity_t **entity = malloc(sizeof(entity_t *) * (HEAD_MAX));
    sfTexture *temp_texture = sfTexture_createFromFile("image/head.png", NULL);

    entity[0] = intruder_init(temp_texture);
    for (int i = 1; i != HEAD_MAX - 1; i++) {
        entity[i] = malloc(sizeof(entity_t));
        entity[i]->sprite = sfSprite_create();
        entity[i]->texture = temp_texture;
        entity[i]->type = rand() % 4;
        entity[i]->scale = vector_create(4, 4);
        entity[i]->vect = speed_randomizer();
        sfSprite_setScale(entity[i]->sprite, entity[i]->scale);
        sfSprite_setTexture(entity[i]->sprite, entity[i]->texture, sfTrue);
        while (entity[i]->type == entity[0]->type)
            entity[i]->type = rand() % 4;
        set_entity_rect(entity[i]);
        set_entity_music(entity[i]);
        entity[i]->pos = position_randomizer(entity[i]);
        sfSprite_setPosition(entity[i]->sprite, entity[i]->pos);
    }
    return (entity);
}
