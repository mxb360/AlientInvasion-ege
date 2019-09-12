#include "background.h"

static PIMAGE _background;

/* ��ʼ������ */
void background_init(void)
{
    _background = newimage();
    getimage(_background, BACKGROUND_IMAGE);
    dprintf("�������ֳ�ʼ����� ...\n");
}

/* ���Ʊ��� */
void background_draw(void)
{
    putimage(0, 0, _background);
}

/* ���ٱ��� */
void background_destroy(void)
{
    delimage(_background);
}
