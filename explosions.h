#ifndef _EXPLOSIONS_H_
#define _EXPLOSIONS_H_

#include "plane_war.h"
#include "dynamic.h"

typedef struct {
    Dynamic *explosion[ENEMY_ALLOWED + 1];
    int     count;
} Explosions;

void explosions_init(Explosions *explosions);
void explosions_create(int x, int y);
void explosions_update(void);
void explosions_draw(void);
void explosions_destroy(void);

#endif
