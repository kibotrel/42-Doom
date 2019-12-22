#include "texture.h"
#include "clean.h"
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

uint32_t    color_mul(uint32_t color, double mul)
{
    int     r;
    int     g;
    int     b;

    r = (color >> 16 & 0xFF);
    g = (color >> 8 & 0xFF);
    b = (color & 0xFF);
    r *= mul;
    g *= mul;
    b *= mul;
    r > 255 ? r = 255 : r;
    g > 255 ? g = 255 : g;
    b > 255 ? b = 255 : b;
    r < 0 ? r = 0 : r;
    g < 0 ? g = 0 : g;
    b < 0 ? b = 0 : b;
    return ((r << 16) | (g << 8) | b);
}

uint32_t    color_add(uint32_t color, double add)
{
    int     r;
    int     g;
    int     b;

    r = (color >> 16 & 0xFF);
    g = (color >> 8 & 0xFF);
    b = (color & 0xFF);
    r += add;
    g += add;
    b += add;
    r > 255 ? r = 255 : r;
    g > 255 ? g = 255 : g;
    b > 255 ? b = 255 : b;
    r < 0 ? r = 0 : r;
    g < 0 ? g = 0 : g;
    b < 0 ? b = 0 : b;
    return ((r << 16) | (g << 8) | b);
}

void	draw_texture(t_env *env, int x, int y1, int y2, int z, uint32_t *middle)
{
	t_pos       p;

    y1 = bound(y1, 0, env->h - 1);
    y2 = bound(y2, 0, env->h - 1);
    p.x = x;
    p.y = y1;
    if (y2 > y1)
    {
        draw_pixel(env, env->sdl.screen, p, 0);
        while (++p.y < y2)
		{
            draw_pixel(env, env->sdl.screen, p, color_add(middle[(p.y % 64) * 64 + x % 64], FOG));
		}
        draw_pixel(env, env->sdl.screen, p, 0);
    }
}
