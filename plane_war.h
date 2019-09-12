#ifndef _PLANE_WAR_H_
#define _PLANE_WAR_H_

#include <stdlib.h>

/* 导入游戏的所有配置设置 */
#include "game_settings.h"

/* 当游戏处于调试模式时，展示控制台，并打印相关信息 */
#ifdef DEBUG_GAME
  #include <stdio.h>
  #define dprintf printf
  #define SHOW_CONSOLE
#else
  #define dprintf(...) ((void) 0)
#endif

/* 导入EGE图形库的所有支持 */
#include <graphics.h>

/* 导入矩形操作 */
#include "rect.h"

#endif 
