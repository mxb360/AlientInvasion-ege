#ifndef _RECT_H_
#define _RECT_H_

typedef struct
{
    short x;
    short y;
    short top;
    short left;
    short right;
    short bottom;
    short width;
    short height;
    short centerx;
    short centery;
} Rect;

void rect_init(Rect *rect, short left, short top, short width, short height);
void rect_setxy(Rect *rect, short x, short y);
void rect_setpos(Rect *rect, short left, short top, short right, short bottom);
void rect_setcenterx(Rect *rect, short centerx);
void rect_setcentery(Rect *rect, short centery);
void rect_setcenter(Rect *rect, short centerx, short centery);
void rect_setleft(Rect *rect, short left, int move);
void rect_setright(Rect *rect, short right, int move);
void rect_settop(Rect *rect, short top, int move);
void rect_setbottom(Rect *rect, short bottom, int move);
void rect_setsize(Rect *rect, short width, short height);
int  rect_overlap(const Rect *rect1, const Rect *rect2, Rect *rect);
int  rect_ispointin(short x, short y, const Rect *rect);

#endif
