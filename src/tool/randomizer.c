/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** randomizer
*/

#include "my_hunter.h"

sfVector2f speed_randomizer(void)
{
    float x = (rand() % 4) + 1;
    float y = (rand() % 4) + 1;

    if (rand() % 2 == 0)
        x *= -1;
    if (rand() % 2 == 0)
        y *= -1;
    return (vector_create(x, y));
}

sfVector2f position_randomizer(entity_t *entity)
{
    float x = (rand() % (int)(1920 - entity->rect.left * entity->scale.x - 700)) + 500;
    float y = (rand() % (int)(1080 - entity->rect.height * entity->scale.y - 150));

    return (vector_create(x, y));
}
