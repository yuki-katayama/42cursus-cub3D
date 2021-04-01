/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:01:04 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/01 01:34:56 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_render_color_buffer(t_sys *s)
{
	mlx_put_image_to_window(
		s->mlx.ptr,
		s->win.ptr,
		s->pixels.ptr,
		0,
		0);
}

void	ft_clear_color_buffer(uint32_t color, t_sys *s)
{
	int	i;

	i = -1;
	while (++i < s->win.w * s->win.h)
		s->pixels.buf[i] = color;
}

void	ft_draw_pixel(int x, int y, uint32_t color, t_sys *s)
{
	s->pixels.buf[(s->win.w * y) + x] = color;
}
