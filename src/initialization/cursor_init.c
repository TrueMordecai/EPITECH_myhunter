/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** cursor_init
*/

#include "my_hunter.h"

static entity_t *cursor_skin_init(void)
{
    entity_t *skin = malloc(sizeof(entity_t));

    skin->sprite = sfSprite_create();
    skin->texture = sfTexture_createFromFile("image/cursor.png", NULL);
    sfSprite_setTexture(skin->sprite, skin->texture, sfTrue);
    sfSprite_setScale(skin->sprite, vector_create(3, 3));
    return (skin);
}

cursor_t *cursor_init(void)
{
    cursor_t *curs = malloc(sizeof(cursor_t));

    curs->skin = cursor_skin_init();
    return (curs);
}
