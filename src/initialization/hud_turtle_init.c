/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** my_hunter
*/

#include "my_hunter.h"

entity_t hud_turtle_init(void)
{
    entity_t entity;

    entity.sprite = sfSprite_create();
    entity.texture = sfTexture_createFromFile("image/turtle.png", NULL);
    entity.rect = rect_create(0, 0, 16, 17);
    sfSprite_setTexture(entity.sprite, entity.texture, sfTrue);
    sfSprite_setPosition(entity.sprite, vector_create(210, 800));
    sfSprite_setTextureRect(entity.sprite, entity.rect);
    sfSprite_setScale(entity.sprite, vector_create(5, 5));
    entity.clock = sfClock_create();
    entity.seconds = 0;
    entity.time = sfTime_Zero;
    return (entity);
}
