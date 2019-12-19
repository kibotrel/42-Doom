#include "vector.h"
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

static int  rgb_to_hex(uint8_t r, uint8_t g, uint8_t b)
{
    return (b << 16 ^ g << 8 ^ r);
}

void        read_bmp(int *ret, char *path, char *buff, int buff_size)
{
    t_vector   bmp;
    int     fd;
    size_t  start;
    int     tmp;

    tmp = 0;
    if ((fd = open(path, O_RDONLY)) == -1)
        return ;
    bmp = v_new(sizeof(uint8_t));
    while ((tmp = read(fd, buff, buff_size)) > 0)
        v_append_raw(&bmp, buff, tmp);
    start = v_size(&bmp) - buff_size;
    tmp = 0;
    while (start + tmp < (size_t)v_size(&bmp))
    {
        ret[tmp / 3] = rgb_to_hex(*(char *)v_get(&bmp, tmp + start),
                *(char *)v_get(&bmp, tmp + 1 + start),
                *(char *)v_get(&bmp, tmp + 2 + start));
        tmp += 3;
    }
    v_del(&bmp);
    close(fd);
}
#include <stdio.h>
void	draw_texture(t_env *env, int x, int y1, int y2, int top, int *middle, int bottom)
{
	t_pos       p;

    y1 = bound(y1, 0, env->h - 1);
    y2 = bound(y2, 0, env->h - 1);
    p.x = x;
    p.y = y1;
    /*if(y2 == y1)
        draw_pixel(env, env->sdl.screen, p, middle);*/
    if (y2 > y1)
    {
        draw_pixel(env, env->sdl.screen, p, top);
        while (++p.y < y2)
		{
			printf("p.y = %i | y2 = %i --- x = %i\n", p.y, y2, x);
            draw_pixel(env, env->sdl.screen, p, middle[(p.y % 64) * 64 + x % 64]);
		}
        draw_pixel(env, env->sdl.screen, p, bottom);
    }
}
