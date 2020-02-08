#include <stdlib.h>
#include "env.h"
#include "structs.h"

char		*frame_720(int frame)
{
	if (!frame)
		return ("./assets/shot0_720.bmp");
	else if (frame == 1)
		return ("./assets/shot1_720.bmp");
	else if (frame == 2)
		return ("./assets/shot2_720.bmp");
	else if (frame == 3)
		return ("./assets/shot3_720.bmp");
	else if (frame == 4)
		return ("./assets/shot4_720.bmp");
	else if (frame == 5)
		return ("./assets/shot5_720.bmp");
	else if (frame == 6)
		return ("./assets/shot6_720.bmp");
	else
		return (NULL);
}

char		*frame_768(int frame)
{
	if (!frame)
		return ("./assets/shot0_768.bmp");
	else if (frame == 1)
		return ("./assets/shot1_768.bmp");
	else if (frame == 2)
		return ("./assets/shot2_768.bmp");
	else if (frame == 3)
		return ("./assets/shot3_768.bmp");
	else if (frame == 4)
		return ("./assets/shot4_768.bmp");
	else if (frame == 5)
		return ("./assets/shot5_768.bmp");
	else if (frame == 6)
		return ("./assets/shot6_768.bmp");
	else
		return (NULL);
}

char		*frame_900(int frame)
{
	if (!frame)
		return ("./assets/shot0_900.bmp");
	else if (frame == 1)
		return ("./assets/shot1_900.bmp");
	else if (frame == 2)
		return ("./assets/shot2_900.bmp");
	else if (frame == 3)
		return ("./assets/shot3_900.bmp");
	else if (frame == 4)
		return ("./assets/shot4_900.bmp");
	else if (frame == 5)
		return ("./assets/shot5_900.bmp");
	else if (frame == 6)
		return ("./assets/shot6_900.bmp");
	else
		return (NULL);
}

t_pos		p2d(int32_t x, int32_t y, int32_t base_x, int32_t base_y)
{
	t_pos p;

	p.x = x * base_x;
	p.y = y * base_y;
	return (p);
}

void		p_update(t_pos *pos, int32_t delta_x, int32_t delta_y)
{
	pos->x += delta_x;
	pos->y += delta_y;
}

uint32_t	life_state(double life)
{
	if (life >= 75)
		return (GREEN);
	else if (life >= 50)
		return (YELLOW);
	else if (life >= 25)
		return (ORANGE);
	else
		return (RED);
}
