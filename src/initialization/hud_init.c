/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** hud_init
*/

#include "my_hunter.h"

static entity_t hud_sprite_init(void)
{
    entity_t bground;

    bground.sprite = sfSprite_create();
    bground.texture = sfTexture_createFromFile("image/hud.png", NULL);
    sfSprite_setTexture(bground.sprite, bground.texture, sfTrue);
    return (bground);
}

static entity_t *hud_portrait_init(void)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile("image/portrait.png", NULL);
    entity->rect = rect_create(0, 0, 61, 48);
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setPosition(entity->sprite, vector_create(200, 110));
    sfSprite_setScale(entity->sprite, vector_create(2, 2));
    return (entity);
}

static char *hud_score_init(void)
{
    char *score = malloc(sizeof(char) * 4);

    score[0] = '0';
    score[1] = '0';
    score[2] = '0';
    score[3] = '\0';
    return (score);
}

static sfText *hud_score_text_init(void)
{
    sfText *text;

    text = sfText_create();
    sfText_setFont(text, sfFont_createFromFile("font/mario.ttf"));
    sfText_setCharacterSize(text, 50);
    sfText_setOutlineColor(text, sfWhite);
    sfText_setColor(text, sfColor_fromRGB(255, 255, 51));
    sfText_setOutlineThickness(text, 1.2);
    sfText_setPosition(text, vector_create(60, 410));
    sfText_setString(text, "Highscore");
    return (text);
}

hud_t *hud_init(void)
{
    hud_t *hud = malloc(sizeof(hud_t));

    hud->round_type = rand() % END_ROUND_TYPE_T;
    hud->round_type_alternative = 0;
    hud->bground = hud_sprite_init();
    hud->score_text = hud_score_text_init();
    hud->portrait = hud_portrait_init();
    hud->score = hud_score_init();
    return (hud);
}
