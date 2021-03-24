/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:02:08 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/24 20:10:00 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

int		ft_set_win(t_sys *s, char *line, int *i)
{
	if (s->win.w != 0 || s->win.h != 0)
		return (-5);
	(*i)++;
	s->win.w = ft_atoi(line, i);
	s->win.h = ft_atoi(line, i);
	s->win.exist = 1;
	if (s->win.w > 2560)
		s->win.w = 2560;
	if (s->win.h > 1400)
		s->win.h = 1400;
	ft_spaceskip(line, i);
	if (s->win.w <= 0 || s->win.h <= 0 || line[*i] != '\0')
		return (-2);
	ft_create_window(s);
	ft_create_pixels(s);
	return (SUCCESS);
}
