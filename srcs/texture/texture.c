#include "texture.h"
#include "vector.h"
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
uint32_t	texture(int *texture)
{
	char	buff[BUFF_SIZE];

	read_bmp(texture, "srcs/texture/wall1.bmp", buff, BUFF_SIZE);
	return (0);
}
