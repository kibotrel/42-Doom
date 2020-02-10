#include "editor.h"

void			init_count(t_count *count)
{
	count->vertex = 0;
	count->sector = 0;
	count->enemy = 0;
	count->portal = 0;
	count->object = 0;
}

void			clean_editor(t_editor *editor, t_env *env)
{
	clear_editor(editor, env);
	if (editor->which_sector)
	{
		delete_sector(&editor->which_sector);
		free(editor->which_sector);
	}
	if (editor->sector)
		free(editor->sector);
	if (editor->vertex)
		free(editor->vertex);
	if (editor->object)
		free(editor->object);
	if (editor->enemy)
		free(editor->enemy);
	if (editor->portals)
		free(editor->portals);
	if (editor->ab)
	{
		delete_vertex(&editor->ab);
		free(editor->ab);
	}
	if (editor->cd)
	{
		delete_vertex(&editor->cd);
		free(editor->ab);
	}
	if (env->sdl.screen)
		SDL_FreeSurface(env->sdl.screen);
	if (env->sdl.win)
		SDL_DestroyWindow(env->sdl.win);
	TTF_Quit();
	SDL_Quit();
	exit(1);
}
