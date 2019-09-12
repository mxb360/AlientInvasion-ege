#ifndef _SOUNDS_H_
#define _SOUNDS_H_

#include "plane_war.h"

void sounds_init(void);
void sounds_play_start(void);
void sounds_stop_start(void);
void sounds_play_game(void);
void sounds_stop_game(void);
void sounds_pause_game(void);
void sounds_resume_game(void);
void sounds_reload_game(void);
void sounds_play_game_over(void);
void sounds_stop_game_over(void);
void sounds_play_fire(void);
void sounds_play_explosion(void);
void sounds_play_death(void);

#endif
