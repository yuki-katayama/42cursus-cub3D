/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:02:08 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/08 13:33:34 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ft_create_mlx(s);
	mlx_get_screen_size(s->mlx.ptr, &w, &h);
	if (s->win.w > w)
		s->win.w = w;
	if (s->win.h > h)
		s->win.h = h;
	return (SUCCESS);
}
