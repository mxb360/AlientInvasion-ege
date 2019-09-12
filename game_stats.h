#ifndef _GAME_STATS_H_
#define _GAME_STATS_H_

#include "plane_war.h"

/* ÓÎÏ·×´Ì¬ */
typedef struct
{
    int game_active;
    int game_over;
    int plane_life;
    int is_plane_hit;
    int score;
    int plane_shoot;
    int plane_lost;
    int is_game_pause;
} GameStats;

void game_stats_init(GameStats *stats);
void reset_stats(GameStats *stats);

#endif 
