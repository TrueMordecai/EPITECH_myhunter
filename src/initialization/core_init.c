/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** core_init
*/

#include "my_hunter.h"

core_t *core_init(void)
{
    core_t *core = malloc(sizeof(core_t));

    core->video_mode.width = RESOLUTION_X;
    core->video_mode.height = RESOLUTION_Y;
    core->video_mode.bitsPerPixel = 32;
    core->mvmt_clock = sfClock_create();
    core->mvmt_time = sfTime_Zero;
    core->mvmt_seconds = (float)0;
    core->name = "my_hunter";
    core->window = sfRenderWindow_create(core->video_mode, core->name,
    sfClose | sfResize, NULL);
    sfRenderWindow_setMouseCursorVisible(core->window, sfFalse);
    sfRenderWindow_setFramerateLimit(core->window, FRAME_RATE);
    return (core);
}
