#include "explosions.h"

static Explosions *_explosions;

/* ±¬Õ¨Í¼Æ¬³õÊ¼»¯ */
void explosions_init(Explosions *explosions)
{
    int i;

    _explosions = explosions;
    for (i = 0; i < ENEMY_ALLOWED + 1; i++)
        _explosions->explosion[i] = NULL;
}

/* ´´½¨Ò»Ö±±¬Õ¨Í¼Æ¬ */
void explosions_create(int x, int y)
{
    int i = 0;

    while (_explosions->explosion[i])
        i++;
    _explosions->explosion[i] = dynamic_init(EXPLOSION_IMAGE, EXPLOSION_SRC_WIDTH,
        EXPLOSION_SRC_HEIGHT, EXPLOSION_WIDTH, EXPLOSION_HEIGHT, EXPLOSION_COLS, 
        EXPLOSION_LINES, EXPLOSION_COUNT, EXPLOSION_TIME);
    dynamic_setxy(_explosions->explosion[i], x, y);
    dprintf("´´½¨±¬Õ¨¶¯Ì¬Í¼[%d] (%d, %d)\n", i, x, y);
}

/* ¸üÐÂ±¬Õ¨ÐÅÏ¢ */
void explosions_update(void)
{
    int i;

    for (i = 0; i < ENEMY_ALLOWED + 1; i++)
        if (_explosions->explosion[i]) {
            dynamic_update(_explosions->explosion[i]);
            if (_explosions->explosion[i]->is_end) {
                dynamic_destroy(_explosions->explosion[i]);
                _explosions->explosion[i] = NULL;
                dprintf("ÒÆ³ý±¬Õ¨¶¯Ì¬Í¼[%d]\n", i);
            }
        }
}

/* »æÖÆ±¬Õ¨Í¼Æ¬ */
void explosions_draw(void)
{
    int i;

    for (i = 0; i < ENEMY_ALLOWED + 1; i++)
        if (_explosions->explosion[i])
            dynamic_draw(_explosions->explosion[i]);
}

/* Ïú»Ù±¬Õ¨Í¼Æ¬ */
void explosions_destroy(void)
{
    int i;

    for (i = 0; i < ENEMY_ALLOWED + 1; i++)
        if (_explosions->explosion[i])
            dynamic_destroy(_explosions->explosion[i]);
}
