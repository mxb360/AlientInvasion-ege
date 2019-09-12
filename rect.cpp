#include "rect.h"

/* 初始化一个矩形 */
void rect_init(Rect *rect, short left, short top, short width, short height)
{
    rect->x = left;
    rect->y = top;
    rect->top = top;
    rect->left = left;
    rect->bottom = top + height;
    rect->right = left + width;
    rect->centerx = left + width / 2;
    rect->centery = top + height / 2;
    rect->width = width;
    rect->height = height;
}

/* 设置矩形的左上角的位置 */
void rect_setxy(Rect *rect, short x, short y)
{
    rect_setleft(rect, x, 1);
    rect_settop(rect, y, 1);
}

/* 设置矩形的左上角的位置 */
void rect_setpos(Rect *rect, short left, short top, short right, short bottom)
{
    rect->top = top;
    rect->bottom = bottom;
    rect->left = left;
    rect->right = right;

    rect->width = rect->right - rect->top;
    rect->height = rect->bottom - rect->top;
    rect->centerx = rect->left + rect->width / 2;
    rect->centery = rect->top + rect->height / 2;
    rect->x = rect->left;
    rect->y = rect->top;
}

/* 设置矩形的中心横坐标 */
void rect_setcenterx(Rect *rect, short centerx)
{
    rect->centerx = centerx;
    rect->left = centerx - rect->width / 2;
    rect->right = centerx + rect->width / 2;
    rect->x = rect->left;
}

/* 设置矩形的中心纵坐标 */
void rect_setcentery(Rect *rect, short centery)
{
    rect->centery = centery;
    rect->top = centery - rect->height / 2;
    rect->bottom = centery + rect->height / 2;
    rect->y = rect->top;
}

/* 设置矩形的中心坐标 */
void rect_setcenter(Rect *rect, short centerx, short centery)
{
    rect_setcenterx(rect, centerx);
    rect_setcentery(rect, centery);
}

/* 设置矩形最左端的位置 */
void rect_setleft(Rect *rect, short left, int move)
{
    rect->left = left;
    if (move) 
        rect->right = rect->left + rect->width;
    else 
        rect->width = rect->right - rect->left;
    rect->centerx = rect->left + rect->width / 2;
    rect->x = rect->left;
}

/* 设置矩形最右端的位置 */
void rect_setright(Rect *rect, short right, int move)
{
    rect->right = right;
    if (move)
        rect->left = rect->right - rect->width;
    else
        rect->width = rect->right - rect->left;
    rect->centerx = rect->left + rect->width / 2;
    rect->x = rect->left;
}

/* 设置矩形最上端的位置 */
void rect_settop(Rect *rect, short top, int move)
{
    rect->top = top;
    
    if (move)
        rect->bottom = rect->top + rect->height;
    else
        rect->height = rect->bottom - rect->top;
    rect->centery = rect->top + rect->height / 2;
    rect->y = rect->top;
}

/* 设置矩形最下端的位置 */
void rect_setbottom(Rect *rect, short bottom, int move)
{
    rect->bottom = bottom;
    if (move)
        rect->top = rect->bottom - rect->height;
    else
        rect->height = rect->bottom - rect->top;
    rect->centery = rect->top + rect->height / 2;
    rect->y = rect->top;
}

/* 设置矩形的大小，保证中心位置不变 */
void rect_setsize(Rect *rect, short width, short height)
{
    rect->width = width;
    rect->height = height;
    rect->top = rect->centery - height / 2;
    rect->bottom = rect->top + height;
    rect->left = rect->centerx - width / 2;
    rect->right = rect->right + width;
    rect->x = rect->left;
    rect->y = rect->top;
}

/* 两个矩形区域是否有重叠，如果重叠并且rect不为NULL，将重叠的矩形存入rect中 */
int rect_overlap(const Rect *rect1, const Rect *rect2, Rect *rect)
{
    int is_overlap;
    
    is_overlap = rect1->right > rect2->left && rect2->right > rect1->left &&
                 rect1->bottom > rect2->top && rect2->bottom > rect1->top;

    if (!is_overlap || !rect)
        return is_overlap;

    rect_setpos(rect,
        rect1->top > rect2->top ? rect1->top : rect2->top,
        rect1->bottom < rect2->bottom ? rect1->bottom : rect2->bottom,
        rect1->left > rect2->left ? rect1->left : rect2->left,
        rect1->right < rect2->right ? rect1->right : rect2->right);

    return is_overlap;
}

/* 点(x, y)是否在矩形内 */
int  rect_ispointin(short x, short y, const Rect *rect)
{
    return x > rect->left && x < rect->right &&
           y > rect->top  && y < rect->bottom;
}
 