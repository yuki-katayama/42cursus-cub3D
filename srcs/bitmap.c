/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:38:47 by cclaude           #+#    #+#             */
/*   Updated: 2021/04/08 15:44:02 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_bdata(t_sys *s, int fd)
{
	int				i;
	int				j;
	uint32_t		*tmp;
	uint32_t		*buf;

	if (!(ft_malloc_p((void **)&buf, \
			sizeof(uint32_t) * s->win.h * s->win.w + 1)))
		return (FAILED);
	i = s->win.w * (s->win.h - 1);
	tmp = buf;
	while (i >= 0)
	{
		j = -1;
		while (++j < s->win.w)
		{
			*tmp = s->pixels.buf[i];
			tmp++;
			i++;
		}
		i -= 2 * s->win.w;
	}
	write(fd, buf, s->win.h * s->win.w * 4);
	return (SUCCESS);
}

static void	ft_binfo(t_sys *s, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = s->win.w;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = 0;
	n = s->win.h;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = 0;
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

static void	ft_bfile(t_sys *s, int fd)
{
	uint32_t				n;

	n = s->win.w * s->win.h * 4 + 14 + 12;
	write(fd, "BM", 2);
	write(fd, &n, 4);
	write(fd, "\0\0", 2);
	write(fd, "\0\0", 2);
	write(fd, "\0\0\0\0", 4);
}

static void	ft_bready(t_sys *s)
{
	ft_cast_all_rays(s);
	ft_clear_color_buffer(WHITE, s);
	ft_render_wall_projection(s);
	ft_render_sprite_projection(s);
}

int	ft_bitmap(t_sys *s)
{
	int		fd;

	ft_bready(s);
	fd = open("bitmap.bmp", O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	ft_bfile(s, fd);
	ft_binfo(s, fd);
	ft_bdata(s, fd);
	close(fd);
	ft_close(s);
	return (SUCCESS);
}
