#include "libft.h"
#include "env.h"
#include "doom.h"

static int	prechecks(int ac, char **av)
{
	if (ac == 2)
		return (ft_isvalidname(av[1], ".data"));
	else
		return (SUCCESS);
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac <= 2)
	{
		if (prechecks(ac, av))
		{
			setup(&env);
			SDL_SetWindowTitle(sdl->win, TITLE);
			SDL_Delay(5000);
			clean_sdl(&env->sdl);
		}
		else
			ft_print_error(E_FILENAME, 1);
	}
	else
		usage();
	return (0);
}
