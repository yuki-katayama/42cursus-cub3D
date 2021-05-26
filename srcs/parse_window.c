/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:02:08 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/22 16:31:31 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_speed(t_sys *s, int w, int h)
{
	double	win_rate;

	win_rate = (s->win.w * s->win.h) / (w * h * 0.5);
	s->player.walk_speed = WALK_SPEED * win_rate;
	s->player.turn_speed = (TURN_SPEED * win_rate) * (PI / 180);
}

int	ft_set_win(t_sys *s, char *line, int *i)
{
	int	w;
	int	h;

	if (s->win.w != 0 || s->win.h != 0)
		return (-5);
	(*i)++;
	s->win.w = ft_atoi(line, i);
	s->win.h = ft_atoi(line, i);
	ft_spaceskip(line, i);
	if (s->win.w <= 1 || s->win.h <= 1 || line[*i] != '\0')
		return (-2);
	s->win.exist = 1;
	mlx_get_screen_size(s->mlx.ptr, &w, &h);
	if (s->bmp == 0 || (s->bmp == 1 && \
		(s->win.h > BMP_MAX_HEIGHT || s->win.w > BMP_MAX_HEIGHT)))
	{
		if (s->win.w > w)
			s->win.w = w;
		if (s->win.h > h)
			s->win.h = h;
	}
	ft_set_speed(s, w, h);
	return (SUCCESS);
}
