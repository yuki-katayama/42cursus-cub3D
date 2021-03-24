/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:01:04 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/24 14:02:34 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

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
		s->pixels.pix_buf[i] = color;
}

void	ft_draw_pixel(int x, int y, uint32_t color, t_sys *s)
{
	s->pixels.pix_buf[(s->win.w * y) + x] = color;
}

void	ft_draw_line(t_line *line, t_sys *s)
{
	int		longest_side_length;
	float	x;
	float	y;
	float	current_x;
	float	current_y;

	x = line->w - line->x;
	y = line->h - line->y;
	longest_side_length = (fabsf(x) >= fabsf(y)
							? fabsf(x) : fabsf(y));
	x = x / (float)longest_side_length;
	y = y / (float)longest_side_length;
	current_x = line->x;
	current_y = line->y;
	while (0 < longest_side_length)
	{
		ft_draw_pixel(round(current_x), round(current_y), line->color, s);
		current_x += x;
		current_y += y;
		longest_side_length--;
	}
}

void	ft_draw_rectangle(t_line *line, t_sys *s)
{
	int	i;
	int	j;

	i = line->x - 1;
	while (++i < line->x + line->w)
	{
		j = line->y - 1;
		while (++j < line->y + line->h)
			ft_draw_pixel(i, j, line->color, s);
	}
}
