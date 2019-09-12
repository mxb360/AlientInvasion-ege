#include "sounds.h"

static MUSIC _start_sound;
static MUSIC _game_sound;
static MUSIC _pause_sound;
static MUSIC _gameover_sound;
static MUSIC _fire_sounds;
static MUSIC _explosion_sound;
static MUSIC _death_sounds;

/* 声音部分初始化 */
void sounds_init(void)
{
    _start_sound.OpenFile(START_SOUND);
    _game_sound.OpenFile(GAME_SOUND);
    _pause_sound.OpenFile(PAUSE_SOUND);
    _gameover_sound.OpenFile(GAME_OVER_SOUND);
    _fire_sounds.OpenFile(PLANE_FIRE_SOUND);
    _explosion_sound.OpenFile(EXPLOSION_SOUND);
    _death_sounds.OpenFile(DEATH_SOUND);
    dprintf("声音部分初始化完成 ...\n");
}

/* 播放开始音乐 */
void sounds_play_start(void)
{
    _start_sound.Play();
    dprintf("播放开始音乐：%s\n", START_SOUND);
}

/* 停止播放开始音乐 */
void sounds_stop_start(void)
{
    _start_sound.Stop();
    dprintf("停止播放开始音乐：%s\n", START_SOUND);
}

/* 播放游戏背景音乐 */
void sounds_play_game(void)
{
    _game_sound.Play(0);
    dprintf("播放游戏背景音乐：%s\n", GAME_SOUND);
}

/* 暂停播放音乐 */
void sounds_pause_game(void)
{
    _game_sound.Pause();
    _pause_sound.Play(0);
    dprintf("暂停播放游戏背景音乐：%s\n", GAME_SOUND);
}

/* 继续播放音乐 */
void sounds_resume_game(void)
{
    _game_sound.Play();
    dprintf("继续播放游戏背景音乐：%s\n", GAME_SOUND);
}

/* 重新加载游戏音乐 */
void sounds_reload_game(void)
{
    if (_game_sound.GetPlayStatus() == MUSIC_MODE_STOP) {
        _game_sound.Play(0);
        dprintf("重新播放游戏背景音乐：%s\n", GAME_SOUND);
    }
}

/* 停止播放游戏背景音乐 */
void sounds_stop_game(void)
{
    _game_sound.Stop();
    dprintf("停止播放游戏背景音乐：%s\n", GAME_SOUND);
}

/* 播放游戏结束音乐 */
void sounds_play_game_over(void)
{
    _gameover_sound.Play(0);
    dprintf("播放游戏结束音乐：%s\n", GAME_OVER_SOUND);
}

/* 停止播放游戏结束音乐 */
void sounds_stop_game_over(void)
{
    _gameover_sound.Stop();
    dprintf("停止播放游戏结束音乐：%s\n", GAME_OVER_SOUND);
}

/* 播放射击音效 */
void sounds_play_fire(void)
{
    _fire_sounds.Play(0);
    //dprintf("播放射击音效: %s\n", PLANE_FIRE_SOUND);
}

/* 播放爆炸音效 */
void sounds_play_explosion(void)
{
    _explosion_sound.Play(0);
    //dprintf("播放爆炸音效: %s\n", EXPLOSION_SOUND);
}

/* 播放飞机阵亡音效 */
void sounds_play_death(void)
{
    _death_sounds.Play(0);
    //dprintf("播放飞机阵亡音效: %s\n", PLANE_FIRE_SOUND);
}
