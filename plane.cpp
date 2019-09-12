#include "plane.h"
#include "enemy.h"
#include "sounds.h"
#include "explosions.h"

static Plane *_plane;

/* 英雄飞机初始化 */
void plane_init(Plane *plane)
{
    PIMAGE image = newimage();
    _plane = plane;
    _plane->image = newimage(PLANE_WIDTH, PLANE_HEIGHT);

    getimage(image, PLANE_IMAGE);
    putimage(_plane->image, 0, 0, PLANE_WIDTH, PLANE_HEIGHT, 
             image, 0, 0, PLANE_SRC_WIDTH, PLANE_SRC_HEIGHT);
    rect_init(&_plane->rect, 0, 0, PLANE_WIDTH, PLANE_HEIGHT);
    delimage(image);

    dprintf("英雄飞机初始化 ...\n");
}

/* 重置英雄飞机 */
void plane_reset(void)
{
    _plane->move_speed = PLANE_SPEED;
    rect_setcenterx(&_plane->rect, WINDOW_WIDTH / 2);
    rect_setbottom(&_plane->rect, WINDOW_HEIGHT - 20, 1);
    dprintf("已重置飞机。飞机中心坐标: (%d, %d)\n", _plane->rect.centerx, _plane->rect.centery);
}

/* 飞机上移 */
void plane_move_up(void)
{
    if (_plane->rect.top - _plane->move_speed <= 0) 
        dprintf("飞机已达到最高点：(%d, %d)\n", _plane->rect.centerx, _plane->rect.centery);
    else    
        rect_setcentery(&_plane->rect, _plane->rect.centery - _plane->move_speed);
}

/* 飞机下移 */
void plane_move_down(void)
{
    if (_plane->rect.bottom + _plane->move_speed >= WINDOW_HEIGHT)
        dprintf("飞机已达到最低点：(%d, %d)\n", _plane->rect.centerx, _plane->rect.centery);
    else
        rect_setcentery(&_plane->rect, _plane->rect.centery + _plane->move_speed);
}

/* 飞机左移 */
void plane_move_left(void)
{
    if (_plane->rect.centerx - _plane->move_speed <= 0)
        dprintf("飞机已达到最左点：(%d, %d)\n", _plane->rect.centerx, _plane->rect.centery);
    else
        rect_setcenterx(&_plane->rect, _plane->rect.centerx - _plane->move_speed);
}

/* 飞机右移 */
void plane_move_right(void)
{
    if (_plane->rect.centerx + _plane->move_speed + 20 >= WINDOW_WIDTH)
        dprintf("飞机已达到最右点：(%d, %d)\n", _plane->rect.centerx, _plane->rect.centery);
    else
        rect_setcenterx(&_plane->rect, _plane->rect.centerx + _plane->move_speed);
}

/* 更新飞机的信息 */
void plane_update(GameStats *stats)
{
    Enemy *enemy;
    static int timer;

    if (stats->is_plane_hit)
        timer++;
    if (timer == PLANE_CREATE_TIME) {
        stats->is_plane_hit = FALSE;
        plane_reset();
        timer = 0;
    }

    if (!stats->game_active || stats->is_plane_hit)
        return;

    if ((enemy = enemy_rect_overlap(&_plane->rect)) != NULL) {
        stats->is_plane_hit = TRUE;
        stats->plane_life--;
        dprintf("英雄飞机阵亡！，剩余生命：%d\n", stats->plane_life);
        enemy_remove(enemy);
        explosions_create(_plane->rect.x, _plane->rect.y);
        sounds_play_death();
    }
}

/* 绘制飞机 */
void plane_draw(GameStats *stats)
{
    if (!stats->game_active || stats->is_plane_hit)
        return;
    putimage_transparent(NULL, _plane->image, _plane->rect.left, _plane->rect.top, BLACK);
}

/* 销毁飞机 */
void plane_destroy(void)
{
    delimage(_plane->image);
}
