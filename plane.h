#ifndef _PLANE_H_
#define _PLANE_H_

#include "plane_war.h"
#include "game_stats.h"

/* Ó¢ÐÛ·É»ú */
typedef struct
{
    PIMAGE image;
    Rect   rect;
    int    move_speed;
} Plane;

void plane_init(Plane *plane);
void plane_reset(void);
void plane_draw(GameStats *stats);
void plane_destroy(void);
void plane_update(GameStats *stats);
void plane_move_up(void);
void plane_move_down(void);
void plane_move_left(void);
void plane_move_right(void);

#endif
