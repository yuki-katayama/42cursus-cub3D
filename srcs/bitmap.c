/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:02:40 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/12 19:02:41 by kyuki            ###   ########.fr       */
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
	free(buf);
	return (SUCCESS);
}

static void	ft_binfo(t_sys *s, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = 0;
	header[0] = (unsigned long)(40);
	n = s->win.w;
	header[4] = (long)(n % 256);
	header[5] = (long)(n / 256 % 256);
	header[6] = (long)(n / 256 / 256 % 256);
	header[7] = 0;
	n = s->win.h;
	header[8] = (long)(n % 256);
	header[9] = (long)(n / 256 % 256);
	header[10] = (long)(n / 256 / 256 % 256);
	header[11] = 0;
	header[12] = (unsigned long)(1);
	header[14] = (unsigned long)(32);
	write(fd, header, 40);
}

static void	ft_bfile(t_sys *s, int fd)
{
	uint32_t				n;
	uint32_t				offset;

	n = s->win.w * s->win.h * 4 + 54;
	offset = 54;
	write(fd, "BM", 2);
	write(fd, &n, 4);
	write(fd, "\0\0", 2);
	write(fd, "\0\0", 2);
	write(fd, &offset, 4);
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
	fd = open("bitmap.bmp", O_WRONLY | O_TRUNC \
				| O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	ft_bfile(s, fd);
	ft_binfo(s, fd);
	ft_bdata(s, fd);
	close(fd);
	ft_close(s);
	return (SUCCESS);
}
