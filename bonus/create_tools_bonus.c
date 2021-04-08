/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tools_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 02:34:33 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/31 20:34:56 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_create_mlx(t_sys *s)
{
	s->mlx.ptr = mlx_init();
}

void	ft_create_window(t_sys *s)
{
	s->win.ptr = mlx_new_window(
		s->mlx.ptr,
		s->win.w,
		s->win.h,
		"cub3d");
}

void	ft_create_pixels(t_sys *s)
{
	int	tmp[0];

	s->pixels.ptr = mlx_new_image(
		s->mlx.ptr,
		s->win.w,
		s->win.h);
	s->pixels.buf = (uint32_t *)mlx_get_data_addr(
		s->pixels.ptr,
		&tmp[0],
		&tmp[0],
		&tmp[0]);
}

void	ft_create_texture(t_sys *s, t_pixel *adr, char *file)
{
	int		tmp[0];

	adr->ptr = mlx_xpm_file_to_image(
		s->mlx.ptr,
		file,
		&s->tex.width,
		&s->tex.height);
	adr->buf = (uint32_t *)mlx_get_data_addr(
		adr->ptr,
		&tmp[0],
		&tmp[0],
		&tmp[0]);
}

int		ft_create_spr_list(t_sys *s)
{
	int		x;
	int		i;
	int		y;

	if (!(s->spr = malloc(sizeof(t_sys) * s->map.num_spr)))
		return (ft_error(-27, -1));
	x = -1;
	i = -1;
	while (++x < s->map.cols)
	{
		y = -1;
		while (++y < s->map.rows)
		{
			if (s->map.table[y][x] == '2')
			{
				s->spr[++i].x = (TILE_SIZE * x) + TILE_SIZE / 2;
				s->spr[i].y = (TILE_SIZE * y) + TILE_SIZE / 2;
			}
		}
	}
	return (SUCCESS);
}
