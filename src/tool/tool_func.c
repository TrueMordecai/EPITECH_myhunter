/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** tool_functiuns, i should implemnt them in a library
*/

#include "my_hunter.h"

void set_entity_rect(entity_t *entity)
{
    if (entity->type == MARIO)
        entity->rect = rect_create(0, 25, 32, 29);
    if (entity->type == LUIGI)
        entity->rect = rect_create(0, 0, 32, 25);
    if (entity->type == YOSHI)
        entity->rect = rect_create(0, 55, 32, 24);
    if (entity->type == WARIO)
        entity->rect = rect_create(0, 80, 32, 31);
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

sfColor color_create(uint r, uint g, uint b, uint a)
{
    sfColor color;

    if (r > 255 || g > 255 || b > 255 || a > 255)
        return (sfBlack);
    color.r = r;
    color.b = b;
    color.g = g;
    color.a = a;
    return (color);
}

sfVector2f vector_create(float x, float y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

sfIntRect rect_create(int top, int left, int height, int width)
{
    sfIntRect rect;

    rect.top = top;
    rect.height = height;
    rect.left = left;
    rect.width = width;
    return (rect);
}
