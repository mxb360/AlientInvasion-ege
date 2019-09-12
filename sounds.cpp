#include "sounds.h"

static MUSIC _start_sound;
static MUSIC _game_sound;
static MUSIC _pause_sound;
static MUSIC _gameover_sound;
static MUSIC _fire_sounds;
static MUSIC _explosion_sound;
static MUSIC _death_sounds;

/* �������ֳ�ʼ�� */
void sounds_init(void)
{
    _start_sound.OpenFile(START_SOUND);
    _game_sound.OpenFile(GAME_SOUND);
    _pause_sound.OpenFile(PAUSE_SOUND);
    _gameover_sound.OpenFile(GAME_OVER_SOUND);
    _fire_sounds.OpenFile(PLANE_FIRE_SOUND);
    _explosion_sound.OpenFile(EXPLOSION_SOUND);
    _death_sounds.OpenFile(DEATH_SOUND);
    dprintf("�������ֳ�ʼ����� ...\n");
}

/* ���ſ�ʼ���� */
void sounds_play_start(void)
{
    _start_sound.Play();
    dprintf("���ſ�ʼ���֣�%s\n", START_SOUND);
}

/* ֹͣ���ſ�ʼ���� */
void sounds_stop_start(void)
{
    _start_sound.Stop();
    dprintf("ֹͣ���ſ�ʼ���֣�%s\n", START_SOUND);
}

/* ������Ϸ�������� */
void sounds_play_game(void)
{
    _game_sound.Play(0);
    dprintf("������Ϸ�������֣�%s\n", GAME_SOUND);
}

/* ��ͣ�������� */
void sounds_pause_game(void)
{
    _game_sound.Pause();
    _pause_sound.Play(0);
    dprintf("��ͣ������Ϸ�������֣�%s\n", GAME_SOUND);
}

/* ������������ */
void sounds_resume_game(void)
{
    _game_sound.Play();
    dprintf("����������Ϸ�������֣�%s\n", GAME_SOUND);
}

/* ���¼�����Ϸ���� */
void sounds_reload_game(void)
{
    if (_game_sound.GetPlayStatus() == MUSIC_MODE_STOP) {
        _game_sound.Play(0);
        dprintf("���²�����Ϸ�������֣�%s\n", GAME_SOUND);
    }
}

/* ֹͣ������Ϸ�������� */
void sounds_stop_game(void)
{
    _game_sound.Stop();
    dprintf("ֹͣ������Ϸ�������֣�%s\n", GAME_SOUND);
}

/* ������Ϸ�������� */
void sounds_play_game_over(void)
{
    _gameover_sound.Play(0);
    dprintf("������Ϸ�������֣�%s\n", GAME_OVER_SOUND);
}

/* ֹͣ������Ϸ�������� */
void sounds_stop_game_over(void)
{
    _gameover_sound.Stop();
    dprintf("ֹͣ������Ϸ�������֣�%s\n", GAME_OVER_SOUND);
}

/* ���������Ч */
void sounds_play_fire(void)
{
    _fire_sounds.Play(0);
    //dprintf("���������Ч: %s\n", PLANE_FIRE_SOUND);
}

/* ���ű�ը��Ч */
void sounds_play_explosion(void)
{
    _explosion_sound.Play(0);
    //dprintf("���ű�ը��Ч: %s\n", EXPLOSION_SOUND);
}

/* ���ŷɻ�������Ч */
void sounds_play_death(void)
{
    _death_sounds.Play(0);
    //dprintf("���ŷɻ�������Ч: %s\n", PLANE_FIRE_SOUND);
}
