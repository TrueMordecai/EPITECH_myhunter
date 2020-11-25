/*
** EPITECH PROJECT, 2020
** my_hunter include
** File description:
** all information for the my _hunter
*/

#ifndef _HUNTER_H_
#define _HUNTER_H_
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Export.h>
#include <time.h>
#include <SFML/Graphics/Rect.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#define HEAD_MAX 150
#define RESOLUTION_X 1920
#define RESOLUTION_Y 1080
#define FRAME_RATE 60
#define CORE game->core
#define ENTITY game->entity[i]
#define INTRUDER game->entity[0]
#define CURSOR game->curs
#define HUD game->hud
#define ROUND_TYPE game->hud->round_type
#define INTRUDER_TYPE game->entity[0]->type
typedef enum {
    LUIGI = 0,
    MARIO,
    YOSHI,
    WARIO,
    END_HEAD_TYPE_T
} head_type_t;

typedef enum {
    GHOST = 0,
    BOUNCE,
    STATUE,
    END_ROUND_TYPE_T
} round_type_t;

typedef struct core_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    sfClock *mvmt_clock;
    sfTime mvmt_time;
    float mvmt_seconds;
    char *name;
} core_t;

typedef struct entity_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfVector2f vect;
    head_type_t type;
    sfMusic *found_sound;
} entity_t;

typedef struct hud_s {
    entity_t bground;
    round_type_t round_type;
    int round_type_alternative;
    entity_t *portrait;
    sfText *score_text;
    sfVector2f test_pos;
    char *score;
    sfClock *timer_clock;
    sfTime timer_time;
    char *timer_str;
    float seconds;
} hud_t;

typedef struct cursor_s {
    sfVector2i pos;
    bool is_click;
    entity_t *skin;
} cursor_t;

typedef struct player_s {
    entity_t player_entity;
} player_t;

typedef struct game_s {
    hud_t *hud;
    core_t *core;
    entity_t **entity;
    cursor_t *curs;
} game_t;
core_t *core_init(void);
sfVector2f position_randomizer(entity_t *entity);
void set_entity_rect(entity_t *entity);
sfVector2f speed_randomizer(void);
entity_t **entity_init(void);
hud_t *hud_init(void);
cursor_t *cursor_init(void);
game_t *game_init(void);
void hud_display(game_t *game);
void bounce_round_type_entity_update(game_t *game);
void ghost_round_type_entity_update(game_t *game);
void statue_round_type_entity_update(game_t *game);
void round_type_index_select(game_t *game);
void entity_display(game_t *game);
bool is_intruder_click(game_t *game);
void display_round(game_t *game);
void cursor_display(game_t *game);
void end_round_win(game_t *game);
void set_entity_music(entity_t *entity);
void game_destroy(game_t *game);
int main_loop(void);
int main(void);
sfColor color_create(uint r, uint g, uint b, uint a);
sfVector2f vector_create(float x, float y);
sfIntRect rect_create(int top, int left, int height, int width);
sfVector2f vector2i_to_vector2f(sfVector2i vect);
bool is_game_over(game_t *game);
#endif
