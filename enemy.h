#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "plane_war.h"
#include "game_stats.h"

typedef struct {
    PIMAGE image;
    Rect   rect;
    int    speed;
    int    score_pointer;
    int    type;
} Enemy;

typedef struct {
    Enemy *enemies[ENEMY_ALLOWED];
    int    enemy_count;
} Enemies;

void  enemy_init(Enemies *enemy);
void  enemy_create_enemy(GameStats *stats);
void  enemy_update(GameStats *stats);
void  enemy_draw(void);
void  enemy_destroy(void);
Enemy *enemy_rect_overlap(Rect *rect);
void  enemy_remove(Enemy *enemy);
void  enemy_clear(void);

#endif
