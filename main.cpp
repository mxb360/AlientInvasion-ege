/* �ɻ���ս С��Ϸ V1.0
 * ʹ��EGEͼ�ο�
 * ������Ϊ��C���򣬵�����EGEͼ�ο��ǻ���C++�ģ����
 * ����ĿΪC++��Ŀ
 *
 * �������ļ� 
 *
 * 2018-8   by Ma Xiaobo
 */

#include "game_functions.h"

int main(void)
{
    Plane plane;
    GameStats stats;
    Bullets bullets;
    Enemies enemy;
    Explosions explosions;

    init_game(&plane, &stats, &bullets, &enemy, &explosions);
    run_game(&plane, &stats);
    quit_game();

    return 0;
}

