#include "editor.h"

void			init_count(t_count *count)
{
	count->vertex = 0;
	count->sector = 0;
	count->enemy = 0;
	count->portal = 0;
	count->object = 0;
}

void			clean_editor(t_editor *editor)
{
	clear_editor(editor);
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
	if (editor->sdl.font)
		TTF_CloseFont(editor->sdl.font);
	if (editor->sdl.screen)
		SDL_FreeSurface(editor->sdl.screen);
	if (editor->sdl.win)
		SDL_DestroyWindow(editor->sdl.win);
	TTF_Quit();
	SDL_Quit();
	exit(1);
}
