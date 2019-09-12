#include "background.h"

static PIMAGE _background;

/* 初始化背景 */
void background_init(void)
{
    _background = newimage();
    getimage(_background, BACKGROUND_IMAGE);
    dprintf("背景部分初始化完成 ...\n");
}

/* 绘制背景 */
void background_draw(void)
{
    putimage(0, 0, _background);
}

/* 销毁背景 */
void background_destroy(void)
{
    delimage(_background);
}
