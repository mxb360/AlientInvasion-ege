#ifndef _GAME_FUNCTIONS_H_
#define _GAME_FUNCTIONS_H_

#include "plane_war.h"
#include "sounds.h"
#include "background.h"
#include "plane.h"
#include "bullets.h"
#include "enemy.h"
#include "explosions.h"
#include "game_stats.h"

void init_game(Plane *plane, GameStats *stats, Bullets *bullets,
               Enemies *enemy, Explosions *explosions);
void run_game(Plane *plane, GameStats *stats);
void quit_game(void);

#endif
