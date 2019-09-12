#ifndef _DYNAMIC_H_
#define _DYNAMIC_H_

#include <graphics.h>
#include "rect.h"

typedef struct
{
    PIMAGE image;
    Rect   rect;
    int    cols;
    int    lines;
    int    thiscount;
    int    count;
    int    is_end;
    int    update_time;
} Dynamic;

void    dynamic_update(Dynamic *dynamic);
void    dynamic_setxy(Dynamic *dynamic, short x, short y);
void    dynamic_draw(Dynamic *dynamic);
void    dynamic_destroy(Dynamic *dynamic);
Dynamic *dynamic_init(const char *filename, int src_w, int src_h,
                      int w, int h, int cols, int lines, int cnt, int updatetime);
#endif
