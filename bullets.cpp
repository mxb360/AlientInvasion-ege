#include "bullets.h"
#include <stdlib.h>
#include "enemy.h"
#include "sounds.h"
#include "explosions.h"

static Bullets *_bullets;

/* 子弹组初始化 */
void bullets_init(Bullets *bullets)
{ 
    int i;
    PIMAGE image = newimage();
    _bullets = bullets;
    _bullets->image = newimage(BULLET_WIDTH, BULLET_HEIGHT);

    getimage(image, BULLET_IMAGE);
    putimage(_bullets->image, 0, 0, BULLET_WIDTH, BULLET_HEIGHT,
        image, 0, 0, BULLET_SRC_WIDTH, BULLET_SRC_HEIGHT);
    
    for (i = 0; i < BULLET_ALLOWED; i++)
        _bullets->bullets[i] = NULL;

    delimage(image);

    dprintf("子弹初始化 ...\n");
}

/* 创建一枚子弹 */
void bullets_create_bullet(Plane *plane)
{
    int i = 0;

    while (i < BULLET_ALLOWED && _bullets->bullets[i])
        i++;

    if (i == BULLET_ALLOWED) {
        dprintf("子弹数已达最大值(%d) 无法再创造子弹！\n", BULLET_ALLOWED);
        return;
    }
        
    if (!(_bullets->bullets[i] = (Bullet *) malloc(sizeof (Bullet)))) {
        dprintf("Error： in bullets_create_bullet() 内存分配失败！\n");
        return;
    }
       
    rect_init(_bullets->bullets[i], 0, 0, BULLET_WIDTH, BULLET_HEIGHT);
    rect_setcentery(_bullets->bullets[i], plane->rect.top);
    rect_setcenterx(_bullets->bullets[i], plane->rect.centerx);
    dprintf("创建子弹[%d] (%d, %d)\n", i, _bullets->bullets[i]->centerx, 
                                          _bullets->bullets[i]->centery);
} 

/* 更新子弹信息 */
void bullets_update(GameStats *stats)
{
    int i;
    Enemy *enemy;

    for (i = 0; i < BULLET_ALLOWED; i++)
        if (_bullets->bullets[i]) {
            rect_setcentery(_bullets->bullets[i], 
                            _bullets->bullets[i]->centery - BULLET_SPEED);

            if (_bullets->bullets[i]->bottom < 0) {
                free(_bullets->bullets[i]);
                _bullets->bullets[i] = NULL;
                dprintf("子弹[%d]越界， 已移除\n", i);
                continue;
            } 
            
            if (!stats->game_active || stats->is_plane_hit)
                continue;

            if ((enemy = enemy_rect_overlap(_bullets->bullets[i])) != NULL) {
                sounds_play_explosion();
                dprintf("子弹[%d]命中一敌机，已移除子弹[%d]\n", i, i);
                stats->score += enemy->score_pointer;
                stats->plane_shoot += 1;
                free(_bullets->bullets[i]);
                _bullets->bullets[i] = NULL;
                explosions_create(enemy->rect.x, enemy->rect.y);
                enemy_remove(enemy);
                
            }
        }
}

/* 清空屏幕上的所有子弹 */
void bullets_clear(void)
{
    int i;

    for (i = 0; i < BULLET_ALLOWED; i++)
        _bullets->bullets[i] = NULL;
}

/* 绘制子弹 */
void bullets_draw(void)
{
    int i;

    for (i = 0; i < BULLET_ALLOWED; i++)
        if (_bullets->bullets[i])
            putimage_transparent(NULL, _bullets->image, _bullets->bullets[i]->left, 
                                       _bullets->bullets[i]->top, BLACK);
}

/* 销毁子弹组 */
void bullets_destroy(void)
{
    int i;

    for (i = 0; i < BULLET_ALLOWED; i++)
        free(_bullets->bullets[i]);
    delimage(_bullets->image);
}
