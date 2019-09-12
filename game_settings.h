/* 飞机大战游戏的基本设置 */

#ifndef _GAME_SETTINGS_H_
#define _GAME_SETTINGS_H_

/* 如果定义此宏，游戏处于调试模式，会保留控制台，并有游戏运行信息输出 */
#define DEBUG_GAME

/* 界面设置 */
#define WINDOW_WIDTH         1400
#define WINDOW_HEIGHT        875
#define BACKGROUND_IMAGE     "images/bg.jpg" 

/* 我方飞机设置 */
#define PLANE_IMAGE          "images/plane.png"
#define PLANE_SRC_WIDTH      197
#define PLANE_SRC_HEIGHT     134
#define PLANE_WIDTH          147
#define PLANE_HEIGHT         100
#define PLANE_LIFE           3
#define PLANE_SPEED          15
#define PLANE_CREATE_TIME    40

/* 子弹设置 */
#define BULLET_IMAGE         "images/bullet.png"
#define BULLET_SRC_WIDTH     44 
#define BULLET_SRC_HEIGHT    161
#define BULLET_WIDTH         20
#define BULLET_HEIGHT        80
#define BULLET_SPEED         20
#define BULLET_TIME          5
#define BULLET_ALLOWED       10

/* 敌机设置 */
#define ENEMY_TYPES          6
#define ENEMYS_IMAGE {       "images/enemy0.png", "images/enemy1.png",  \
                             "images/enemy2.png", "images/enemy3.png",  \
                             "images/enemy4.png", "images/enemy5.png",  }
#define ENEMY_SRC_WIDTH      {443, 482, 565, 465, 542, 403, }
#define ENEMY_SRC_HEIGHT     {331, 289, 367, 347, 276, 253, }
#define ENEMYS_WIDTH         {100, 80, 100, 80, 50, 50, }
#define ENEMYS_HEIGHT        {100, 80, 100, 80, 50, 50, }
#define ENEMYS_SPEED         {1, 3, 1, 3, 5, 5, }
#define ENEMYS_SCORE         {100, 200, 100, 200, 300, 300, }
#define ENEMY_CREATE_TIME    10
#define ENEMY_CREATE_FRE     3
#define ENEMY_ALLOWED        20

/* 爆炸设置 */
#define EXPLOSION_IMAGE      "images/explosion.png"
#define EXPLOSION_SRC_WIDTH  487
#define EXPLOSION_SRC_HEIGHT 120
#define EXPLOSION_WIDTH      80
#define EXPLOSION_HEIGHT     120
#define EXPLOSION_COLS       6
#define EXPLOSION_LINES      1
#define EXPLOSION_COUNT      6
#define EXPLOSION_TIME       2

/* 声音设置 */
#define START_SOUND          "sounds/start.wav"
#define GAME_SOUND           "sounds/game.wav"
#define PAUSE_SOUND          "sounds/pause.wav"
#define GAME_OVER_SOUND      "sounds/gameover.wav"
#define PLANE_FIRE_SOUND     "sounds/fire.wav"
#define EXPLOSION_SOUND      "sounds/explosion.wav"
#define DEATH_SOUND          "sounds/death.wav"

/* 字体设置 */
#define GAME_FONT            ""

#endif 
