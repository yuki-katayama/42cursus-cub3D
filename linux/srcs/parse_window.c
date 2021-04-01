/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:02:08 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/31 13:21:34 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_set_win(t_sys *s, char *line, int *i)
{
	if (s->win.w != 0 || s->win.h != 0)
		return (-5);
	(*i)++;
	s->win.w = ft_atoi(line, i);
	s->win.h = ft_atoi(line, i);
	if (s->win.w > 2240)
		s->win.w = 2240;
	if (s->win.h > 1260)
		s->win.h = 1260;
	ft_spaceskip(line, i);
	if (s->win.w <= 0 || s->win.h <= 0 || line[*i] != '\0')
		return (-2);
	s->win.exist = 1;
	ft_create_mlx(s);
	if (s->bmp == 1)
		ft_create_window(s);
	ft_create_pixels(s);
	return (SUCCESS);
}
