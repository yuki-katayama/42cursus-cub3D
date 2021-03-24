/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 02:34:33 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/25 00:26:37 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

void	ft_create_window(t_sys *s)
{
	s->mlx.ptr = mlx_init();
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
	s->pixels.pix_buf = (uint32_t *)malloc(
		sizeof(uint32_t) * (s->win.w * s->win.h));
	s->pixels.pix_buf = (uint32_t *)mlx_get_data_addr(
		s->pixels.ptr,
		&tmp[0],
		&tmp[0],
		&tmp[0]);
}

void	ft_create_texture(t_sys *s, uint32_t **adr, char *file)
{
	void	*ptr;
	int		tmp[0];

	ptr = mlx_xpm_file_to_image(
		s->mlx.ptr,
		file,
		&s->tex.width,
		&s->tex.height);
	*adr = (uint32_t *)mlx_get_data_addr(
		ptr,
		&tmp[0],
		&tmp[0],
		&tmp[0]);
	free(ptr);
}

int		ft_create_spr_list(t_sys *s)
{
	int		x;
	int		i;
	int		y;

	if (!(s->spr = malloc(sizeof(t_sys) * s->map.num_spr)))
		return (ft_error(-27, NAN));
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
