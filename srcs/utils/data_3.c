#include "structs.h"

t_pos	p2d(int32_t x, int32_t y, int32_t base_x, int32_t base_y)
{
	t_pos p;

	p.x = x * base_x;
	p.y = y * base_y;
	return (p);
}

void	p_update(t_pos *pos, int32_t delta_x, int32_t delta_y)
{
	pos->x += delta_x;
	pos->y += delta_y;
}
