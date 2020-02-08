#include <stdlib.h>

char		*frame_1080(int frame)
{
	if (!frame)
		return ("./assets/shot0_1080.bmp");
	else if (frame == 1)
		return ("./assets/shot1_1080.bmp");
	else if (frame == 2)
		return ("./assets/shot2_1080.bmp");
	else if (frame == 3)
		return ("./assets/shot3_1080.bmp");
	else if (frame == 4)
		return ("./assets/shot4_1080.bmp");
	else if (frame == 5)
		return ("./assets/shot5_1080.bmp");
	else if (frame == 6)
		return ("./assets/shot6_1080.bmp");
	else
		return (NULL);
}
