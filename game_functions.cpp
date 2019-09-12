#include "game_functions.h"


/* 如果游戏结束 */
void if_game_over(GameStats *stats)
{
    if (stats->game_over)
        return;
    if (stats->plane_life == 0) {
        stats->game_over = TRUE;
        stats->game_active = FALSE;
        sounds_stop_game();
        sounds_play_game_over();
        dprintf("Game Over\n");
    }
}

/* 游戏的显示信息 */
void show_game_info(GameStats *stats)
{
    setfont(30, 0, GAME_FONT);
    setcolor(YELLOW);
    setbkmode(TRANSPARENT);
    xyprintf(10, 10, "生命：%d", stats->plane_life);
    xyprintf(10, 50, "得分： %d", stats->score);
    xyprintf(10, 90, "击落： %d", stats->plane_shoot);
    xyprintf(10, 130, "错失： %d", stats->plane_lost);
    setcolor(LIGHTMAGENTA);
    outtextxy(WINDOW_WIDTH - 250, 10,  "操作说明：");
    outtextxy(WINDOW_WIDTH - 250, 50,  "方向键：移动");
    outtextxy(WINDOW_WIDTH - 250, 90,  "空格键：射击");
    outtextxy(WINDOW_WIDTH - 250, 130, "回车键：暂停/继续");
    outtextxy(WINDOW_WIDTH - 250, 170, "   Q键：退出");
    if (stats->is_game_pause || !stats->game_active || stats->game_over) {
        setfont(90, 0, GAME_FONT);
        setcolor(RED);
        setbkcolor(GREEN);
        setbkmode(OPAQUE);
        if (stats->is_game_pause)
            rectprintf(WINDOW_WIDTH/2 - 200, WINDOW_HEIGHT/2, 400, 100, "继续游戏");
        else {
            rectprintf(WINDOW_WIDTH/2 - 200, WINDOW_HEIGHT/2, 400, 100, "开始游戏");
            setbkmode(TRANSPARENT);
            if (stats->game_over)
                rectprintf(WINDOW_WIDTH/2-225, WINDOW_HEIGHT/2-150, 450, 100, "GAME OVER");
            else
                rectprintf(WINDOW_WIDTH/2-250, WINDOW_HEIGHT/2-150, 500, 100, "外星人入侵");
        }
    }
}

/* 开始游戏 */
void start_game(GameStats *stats)
{
    reset_stats(stats);
    enemy_clear();
    bullets_clear();
    sounds_stop_start();
    sounds_stop_game_over();
    sounds_play_game();
    dprintf("游戏开始！\n");
}

/* 开始按键是否被点击 */
void check_start_button(GameStats *stats)
{
    int x, y;
    mousepos(&x, &y);
    if (x >= WINDOW_WIDTH / 2 - 200 && x <= WINDOW_WIDTH / 2 + 200 &&
        y >= WINDOW_HEIGHT / 2 && y <= WINDOW_HEIGHT / 2 + 400)
        if (stats->is_game_pause) {
            dprintf("继续游戏\n");
            stats->is_game_pause = FALSE;
            sounds_resume_game();
        }
        else if (!stats->game_active)
            start_game(stats);
}

/* 检测按键，鼠标事件 */
void check_events(Plane *plane, GameStats *stats)
{
    /* 退出游戏 */
    if (keystate('Q') || keystate('q'))
        quit_game();
    
    if (!stats->is_game_pause && stats->game_active && !stats->is_plane_hit) {
        if (keystate(VK_UP))
            plane_move_up();
        if (keystate(VK_DOWN))
            plane_move_down();
        if (keystate(VK_LEFT))
            plane_move_left();
        if (keystate(VK_RIGHT))
            plane_move_right();
    }

    if (kbhit()) {
        switch (getch()) {
        case VK_SPACE:
            if (!stats->is_game_pause && stats->game_active) {
                bullets_create_bullet(plane);
                sounds_play_fire();
            }
            break;
        case VK_RETURN:
            dprintf("回车\n");
            if (stats->game_active) {
                if (stats->is_game_pause) {
                    dprintf("继续游戏\n");
                    stats->is_game_pause = FALSE;
                    sounds_resume_game();
                } else {
                    dprintf("暂停游戏\n");
                    stats->is_game_pause = TRUE;
                    sounds_pause_game();
                }
            } else
                start_game(stats);
            break;
        }
    }

    if ((!stats->game_active || stats->is_game_pause) && mousemsg()) {
        mouse_msg msg = getmouse();
        flushmouse();
        if (msg.is_left())
            check_start_button(stats);
    }
}

/* 更新屏幕 */
void update_screen(GameStats *stats)
{
    background_draw();
    bullets_draw();
    enemy_draw();
    plane_draw(stats);
    explosions_draw();
}


/* 初始化游戏 */
void init_game(Plane *plane, GameStats *stats, Bullets *bullets, 
               Enemies *enemy, Explosions *explosions)
{
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
    setcaption("飞机大战");
    game_stats_init(stats);
    plane_init(plane);
    bullets_init(bullets);
    enemy_init(enemy);
    explosions_init(explosions);
    background_init();
    sounds_init();
    
    dprintf("游戏初始化完成！\n");
}

/* 运行游戏 */
void run_game(Plane *plane, GameStats *stats)
{
    background_draw();
    plane_reset();
    sounds_play_start();
    for (; is_run(); delay_fps(50)) {
        check_events(plane, stats);
        if (!stats->is_game_pause) {
            plane_update(stats);
            bullets_update(stats);
            enemy_update(stats);
            enemy_create_enemy(stats);
            explosions_update();
            update_screen(stats);
            if_game_over(stats);
            if (stats->game_active)
                sounds_reload_game();
        }
        show_game_info(stats);
    }
}

/* 退出游戏 */
void quit_game(void)
{
    dprintf("退出游戏 ...\n");
    background_destroy();
    plane_destroy();
    bullets_destroy();
    closegraph();
    exit(0);
}
