/* 飞机大战 小游戏 V1.0
 * 使用EGE图形库
 * 本程序为纯C程序，但由于EGE图形库是基于C++的，因此
 * 本项目为C++项目
 *
 * 程序主文件 
 *
 * 2018-8   by Ma Xiaobo
 */

#include "game_functions.h"

int main(void)
{
    Plane plane;
    GameStats stats;
    Bullets bullets;
    Enemies enemy;
    Explosions explosions;

    init_game(&plane, &stats, &bullets, &enemy, &explosions);
    run_game(&plane, &stats);
    quit_game();

    return 0;
}

