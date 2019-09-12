#include "plane.h"
#include "enemy.h"
#include "sounds.h"
#include "explosions.h"

static Plane *_plane;

/* Ӣ�۷ɻ���ʼ�� */
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

    dprintf("Ӣ�۷ɻ���ʼ�� ...\n");
}

/* ����Ӣ�۷ɻ� */
void plane_reset(void)
{
    _plane->move_speed = PLANE_SPEED;
    rect_setcenterx(&_plane->rect, WINDOW_WIDTH / 2);
    rect_setbottom(&_plane->rect, WINDOW_HEIGHT - 20, 1);
    dprintf("�����÷ɻ����ɻ���������: (%d, %d)\n", _plane->rect.centerx, _plane->rect.centery);
}

/* �ɻ����� */
void plane_move_up(void)
{
    if (_plane->rect.top - _plane->move_speed <= 0) 
        dprintf("�ɻ��Ѵﵽ��ߵ㣺(%d, %d)\n", _plane->rect.centerx, _plane->rect.centery);
    else    
        rect_setcentery(&_plane->rect, _plane->rect.centery - _plane->move_speed);
}

/* �ɻ����� */
void plane_move_down(void)
{
    if (_plane->rect.bottom + _plane->move_speed >= WINDOW_HEIGHT)
        dprintf("�ɻ��Ѵﵽ��͵㣺(%d, %d)\n", _plane->rect.centerx, _plane->rect.centery);
    else
        rect_setcentery(&_plane->rect, _plane->rect.centery + _plane->move_speed);
}

/* �ɻ����� */
void plane_move_left(void)
{
    if (_plane->rect.centerx - _plane->move_speed <= 0)
        dprintf("�ɻ��Ѵﵽ����㣺(%d, %d)\n", _plane->rect.centerx, _plane->rect.centery);
    else
        rect_setcenterx(&_plane->rect, _plane->rect.centerx - _plane->move_speed);
}

/* �ɻ����� */
void plane_move_right(void)
{
    if (_plane->rect.centerx + _plane->move_speed + 20 >= WINDOW_WIDTH)
        dprintf("�ɻ��Ѵﵽ���ҵ㣺(%d, %d)\n", _plane->rect.centerx, _plane->rect.centery);
    else
        rect_setcenterx(&_plane->rect, _plane->rect.centerx + _plane->move_speed);
}

/* ���·ɻ�����Ϣ */
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
        dprintf("Ӣ�۷ɻ���������ʣ��������%d\n", stats->plane_life);
        enemy_remove(enemy);
        explosions_create(_plane->rect.x, _plane->rect.y);
        sounds_play_death();
    }
}

/* ���Ʒɻ� */
void plane_draw(GameStats *stats)
{
    if (!stats->game_active || stats->is_plane_hit)
        return;
    putimage_transparent(NULL, _plane->image, _plane->rect.left, _plane->rect.top, BLACK);
}

/* ���ٷɻ� */
void plane_destroy(void)
{
    delimage(_plane->image);
}
