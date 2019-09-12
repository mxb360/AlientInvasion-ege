#include "game_stats.h"

void game_stats_init(GameStats *stats)
{
    reset_stats(stats);
    stats->game_active = FALSE;
}

void reset_stats(GameStats *stats)
{
    stats->game_active = TRUE;
    stats->game_over = FALSE;
    stats->is_plane_hit = FALSE;
    stats->plane_life = PLANE_LIFE;
    stats->is_game_pause = FALSE;
    stats->score = 0;
    stats->plane_shoot = 0;
    stats->plane_lost = 0;
}
