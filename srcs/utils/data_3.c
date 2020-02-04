#include "env.h"
#include "structs.h"

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
