#ifndef ENV_H
# define ENV_H

/*
**	Useful macros
*/

# define WIDTH		620
# define TITLE		"Doom-Nukem v0.0.1"
# define ERROR		0
# define HEIGHT		480
# define SUCCESS	1

/*
**	Error messages
*/

# define E_SDL_WIN	"\033[31;1mError:\033[0m Can't create SDL window." //3
# define E_FILENAME	"\033[31;1mError:\033[0m Incorrect filename (*.data)." //1
# define E_SDL_INIT	"\033[31;1mError:\033[0m Can't init SDL connexion." //2

#endif
