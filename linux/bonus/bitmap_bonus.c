/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:38:47 by cclaude           #+#    #+#             */
/*   Updated: 2021/03/31 20:34:42 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void		ft_bdata(t_sys *s, int fd)
{
	int				i;
	int				j;

	i = s->win.w * (s->win.h - 1);
	while (i >= 0)
	{
		j = -1;
		while (++j < s->win.w)
		{
			write(fd, &s->pixels.buf[i], 4);
			i++;
		}
		i -= 2 * s->win.w;
	}
}

static void		ft_binfo(t_sys *s, int fd)
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

static void		ft_bfile(t_sys *s, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = 'B';
	header[1] = 'M';
	n = s->win.w * s->win.h * 4 + 14 + 12;
	header[2] = (unsigned char)n;
	write(fd, header, 14);
}

static void		ft_bready(t_sys *s)
{
	ft_cast_all_rays(s);
	ft_clear_color_buffer(WHITE, s);
	ft_render_wall_projection(s);
	ft_render_sprite_projection(s);
}

int				ft_bitmap(t_sys *s)
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
