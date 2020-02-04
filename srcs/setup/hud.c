
#include <math.h>
#include "libft.h"
#include "utils.h"

void	setup_debug_cam(t_env *env, t_cam *cam, char **str)
{
	t_vec3d			v;

	v = cam->v;
	str[0] = (cam->v.z ? ft_strdup("True") : ft_strdup("False"));
	str[1] = (cam->fly > 0 ? ft_strdup("On") : ft_strdup("Off"));
	str[2] = (cam->ground ? ft_strdup("True") : ft_strdup("False"));
	str[3] = (cam->sneak ? ft_strdup("True") : ft_strdup("False"));
	str[4] = (v.x || v.y || v.z ? ft_strdup("True") : ft_strdup("False"));
	str[5] = ft_itoa((inter(round((1 / (cam->fov.x / env->h)) * 56), 30, 245)));
	str[6] = ft_itoa((int)fabs(ft_degrees(env->cam.angle)) % 360);
	dimensions(&str[7], cam->pos.x, cam->pos.z, cam->pos.y);
	dimensions(&str[8], v.x, v.z, v.y);
	str[9] = ft_itoa(env->data.fps);
	str[10] = ft_itoa(cam->sector);
	if ((cam->sneak && cam->speed == 1) || cam->speed > 1)
		str[11] = ft_strdup("On");
	else
		str[11] = ft_strdup("Off");
}

void	setup_debug_sector(t_sector *sector, char **str)
{
	str[0] = ft_itoa(sector->points);
	str[1] = precision(sector->ceil, 2);
	str[2] = precision(sector->floor, 2);
	str[3] = precision(sector->gravity, 2);
	str[4] = precision(sector->friction, 2);
}
