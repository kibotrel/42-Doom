#include "editor.h"

void	delete_player(t_ed_player *player)
{
	player->x = -5;
	player->y = -5;
	player->angle = 90;
	player->sector = -1;
}

void	rotate_player(t_ed_player *player, bool rotation)
{
	if (!player)
		return ;
	if (rotation == false)
		player->angle += 10;
	else
		player->angle -= 10;
	if (player->angle >= 361)
		player->angle = 0;
	else if (player->angle <= -1)
		player->angle = 360;
}
