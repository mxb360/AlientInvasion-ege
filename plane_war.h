#ifndef _PLANE_WAR_H_
#define _PLANE_WAR_H_

#include <stdlib.h>

/* ������Ϸ�������������� */
#include "game_settings.h"

/* ����Ϸ���ڵ���ģʽʱ��չʾ����̨������ӡ�����Ϣ */
#ifdef DEBUG_GAME
  #include <stdio.h>
  #define dprintf printf
  #define SHOW_CONSOLE
#else
  #define dprintf(...) ((void) 0)
#endif

/* ����EGEͼ�ο������֧�� */
#include <graphics.h>

/* ������β��� */
#include "rect.h"

#endif 
