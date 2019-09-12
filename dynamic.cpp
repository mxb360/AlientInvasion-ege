#include "dynamic.h"
#include <stdlib.h>

/* 初始化动态图 */
Dynamic *dynamic_init(const char *filename, int src_w, int src_h, 
                      int w, int h, int cols, int lines, int cnt, int updatetime)
{
    Dynamic *dynamic;
    PIMAGE image;

    dynamic = (Dynamic *) malloc(sizeof (Dynamic));
    if (dynamic == NULL)
        return NULL;

    dynamic->cols = cols;
    dynamic->lines = lines;
    dynamic->count = cnt;
    dynamic->thiscount = 0;
    dynamic->update_time = updatetime;
    dynamic->is_end = FALSE;

    image = newimage();
    getimage(image, filename);
    dynamic->image = newimage(w * cols, h * lines);
    putimage(dynamic->image, 0, 0, w * cols, h * lines, image, 0, 0, src_w, src_h);
    delimage(image);
    rect_init(&dynamic->rect, 0, 0, w, h);

    return dynamic;
}

/* 更新动态图 */
void dynamic_update(Dynamic *dynamic)
{
    static int time = 0;
    if (++time == dynamic->update_time) {
        dynamic->thiscount++;
        if (dynamic->thiscount == dynamic->count) {
            dynamic->thiscount = 0;
            dynamic->is_end = TRUE;
        }
        time = 0;
    }
}

/* 设置动态图的位置 */
void dynamic_setxy(Dynamic *dynamic, short x, short y)
{
    rect_setxy(&dynamic->rect, x, y);
}

/* 绘制动态图 */
void dynamic_draw(Dynamic *dynamic)
{
    int x = dynamic->thiscount % dynamic->cols * dynamic->rect.width;
    int y = dynamic->thiscount / dynamic->cols * dynamic->rect.height;

    putimage_transparent(NULL, dynamic->image, dynamic->rect.left, dynamic->rect.top,
                         BLACK, x, y, dynamic->rect.width, dynamic->rect.height);
}

/* 销毁该动态图 */
void dynamic_destroy(Dynamic *dynamic)
{
    delimage(dynamic->image);
    free(dynamic);
}
