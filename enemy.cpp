#include "enemy.h"

static PIMAGE   _images[ENEMY_TYPES];
static Rect     _rect[ENEMY_TYPES];
static Enemies *_enemy;

static int _enemy_speed[ENEMY_TYPES]  = ENEMYS_SPEED;
static int _enemy_width[ENEMY_TYPES]  = ENEMYS_WIDTH;
static int _enemy_height[ENEMY_TYPES] = ENEMYS_HEIGHT;
static int _enemy_score[ENEMY_TYPES]  = ENEMYS_SCORE;

/* 敌机初始化 */
void enemy_init(Enemies *enemy)
{
     const char *images_str[ENEMY_TYPES]       = ENEMYS_IMAGE;
     int         enemy_src_width[ENEMY_TYPES]  = ENEMY_SRC_WIDTH;
     int         enemy_src_height[ENEMY_TYPES] = ENEMY_SRC_WIDTH;
     int         i;

     _enemy = enemy;
     for (i = 0; i < ENEMY_TYPES; i++) {
         PIMAGE image = newimage();
         _images[i] = newimage(_enemy_width[i], _enemy_height[i]);

         getimage(image, images_str[i]);
         putimage(_images[i], 0, 0, _enemy_width[i], _enemy_height[i],
                   image, 0, 0, enemy_src_width[i], enemy_src_height[i]);
         delimage(image);
     }

     for (i = 0; i < ENEMY_ALLOWED; i++)
         _enemy->enemies[i] = NULL;

     dprintf("初始化敌机 ...\n");
}

void enemy_create_enemy(GameStats *stats)
{
    int i = 0;
    int type, x;
    static int time = 0;

    if (!stats->game_active || stats->is_game_pause)
        return;

    if (++time < ENEMY_CREATE_TIME)
        return;
    time = 0;
    if (random(ENEMY_CREATE_FRE))
        return;

    type = random(ENEMY_TYPES);
    x = random(WINDOW_WIDTH);

    while (i < ENEMY_ALLOWED && _enemy->enemies[i])
        i++;

    if (i == ENEMY_ALLOWED) {
        dprintf("敌机数已达最大值(%d) 无法再创造敌机！\n", BULLET_ALLOWED);
        return;
    }

    if (!(_enemy->enemies[i] = (Enemy *) malloc(sizeof (Enemy)))) {
        dprintf("Error： in enemy_create_enemy() 内存分配失败！\n");
        return;
    }

    _enemy->enemies[i]->type = type;
    _enemy->enemies[i]->image = _images[type];
    _enemy->enemies[i]->speed = _enemy_speed[type];
    _enemy->enemies[i]->score_pointer = _enemy_score[type];
    rect_init(&_enemy->enemies[i]->rect, 0, -_enemy_height[type], 
               _enemy_width[type], _enemy_height[type]);
    rect_setcenterx(&_enemy->enemies[i]->rect, x);
    dprintf("创建敌机%d[%d] (%d, %d)\n", type, i, _enemy->enemies[i]->rect.centerx,
                                                 _enemy->enemies[i]->rect.centery);
}

void enemy_update(GameStats *stats)
{
    int i;

    for (i = 0; i < ENEMY_ALLOWED; i++)
        if (_enemy->enemies[i]) {
            rect_setcentery(&_enemy->enemies[i]->rect,
                             _enemy->enemies[i]->rect.centery + 
                             _enemy_speed[_enemy->enemies[i]->type]);

            if (_enemy->enemies[i]->rect.top > WINDOW_HEIGHT) {
                if (stats->game_active) {
                    stats->plane_lost++;
                    if (stats->score - _enemy->enemies[i]->score_pointer / 2 >= 0)
                        stats->score -= _enemy->enemies[i]->score_pointer / 2;
                }
                dprintf("敌机%d[%d]越界， 已移除\n", _enemy->enemies[i]->type, i);
                free(_enemy->enemies[i]);
                _enemy->enemies[i] = NULL;
            } 
        }
}

/* 是否有矩形框与敌机重叠 */
Enemy *enemy_rect_overlap(Rect *rect)
{
    int i;

    for (i = 0; i < ENEMY_ALLOWED; i++)
        if (_enemy->enemies[i] && rect_overlap(rect, &_enemy->enemies[i]->rect, NULL))
            return _enemy->enemies[i];
    return NULL;
}

void enemy_clear(void)
{
    int i;

    for (i = 0; i < ENEMY_ALLOWED; i++)
        _enemy->enemies[i] = NULL;
}

void enemy_remove(Enemy *enemy)
{
    int i;

    if (enemy == NULL)
        return;

    for (i = 0; i < ENEMY_ALLOWED; i++)
        if (_enemy->enemies[i] == enemy) {
            dprintf("移除敌机%d[%d]\n", _enemy->enemies[i]->type, i);
            free(_enemy->enemies[i]);
            _enemy->enemies[i] = NULL;
            return;
        }
}

void enemy_draw(void)
{
    int i;

    for (i = 0; i < ENEMY_ALLOWED; i++)
        if (_enemy->enemies[i])
            putimage_transparent(NULL, _images[_enemy->enemies[i]->type], 
                                       _enemy->enemies[i]->rect.left,
                                       _enemy->enemies[i]->rect.top, BLACK);
}

void enemy_destroy(void)
{
    int i;

    for (i = 0; i < ENEMY_ALLOWED; i++) {
        free(_enemy->enemies[i]);
        delimage(_images[i]);
    }
}
