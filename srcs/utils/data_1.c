#include "game.h"

t_item	item(uint32_t sector, uint32_t min, uint32_t max)
{
	t_item	item;

	item.sector = sector;
	item.min = min;
	item.max = max;
	return (item);
}
