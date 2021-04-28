/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:20:32 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/28 22:52:57 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_line01(t_sys *s, char *line, int *i)
{
	if (line[0] == 'R' && line[1] == ' ' && !s->map.already)
		s->err = ft_set_win(s, line, i);
	else if (s->win.w <= 0 || s->win.h <= 0)
		s->err = -13;
	else if (line[0] == 'N' && line[1] == 'O' \
				&& line[2] == ' ' && !s->map.already)
		s->err = ft_set_tex(s, &s->tex.n, line, i);
	else if (line[0] == 'S' && line[1] == 'O' \
				&& line[2] == ' ' && !s->map.already)
		s->err = ft_set_tex(s, &s->tex.s, line, i);
	else if (line[0] == 'W' && line[1] == 'E' \
				&& line[2] == ' ' && !s->map.already)
		s->err = ft_set_tex(s, &s->tex.w, line, i);
	if (s->err < 0)
		return (-1);
	return (SUCCESS);
}

static void	ft_check_line02(t_sys *s, char *line, int *i)
{
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' && !s->map.already)
		s->err = ft_set_tex(s, &s->tex.e, line, i);
	else if (line[0] == 'S' && line[1] == ' ' \
				&& !s->map.already)
		s->err = ft_set_tex(s, &s->tex.i, line, i);
	else if (line[0] == 'F' && line[1] == ' ' \
				&& !s->map.already)
		s->err = ft_set_colors(&s->tex.f, line, i);
	else if (line[0] == 'C' && line[1] == ' ' \
				&& !s->map.already)
		s->err = ft_set_colors(&s->tex.c, line, i);
	else if (line[0] == '1' || line[0] == ' ' || line[0] == '0' || line[0] == '2' \
				|| (s->map.rows != 0 && line[0] == '\0'))
	{
		s->map.already = 1;
		s->err = ft_set_map(s, line, i);
	}
}

int	ft_check_line(t_sys *s, char *line, int row)
{
	int	i;

	i = 0;
	if ((s->map.max_rows == row && line[0] == '\0'))
		return (SUCCESS);
	if (ft_check_line01(s, line, &i) == 0)
		ft_check_line02(s, line, &i);
	if (ft_spaceskip(line, &i) && s->err == 0 && line[i] != '\0')
		s->err = -3;
	if (s->err < 0)
		return (ft_error(s->err, row));
	return (SUCCESS);
}

static void	ft_check_all2(t_sys *s)
{
	if (s->tex.n.ptr == NULL)
		s->err = -9;
	else if (s->tex.s.ptr == NULL)
		s->err = -10;
	else if (s->tex.w.ptr == NULL)
		s->err = -11;
	else if (s->tex.e.ptr == NULL)
		s->err = -12;
	else if (s->tex.i.ptr == NULL)
		s->err = -30;
	else if (s->tex.f == -1)
		s->err = -31;
	else if (s->tex.c == -1)
		s->err = -32;
	else if (s->map.already == 0)
		s->err = -17;
	else if (s->player.x == 0 && s->player.y == 0)
		s->err = -23;
}

int	ft_check_all(t_sys *s)
{
	ft_check_all2(s);
	if (s->err == 0)
	{
		s->err = ft_check_map(s);
		if (s->err < 0)
		{
			if (s->err == -1)
				s->err = -25;
			else if (s->err == -2)
				s->err = -33;
		}
	}
	if (s->err < 0)
		return (ft_error(s->err, -1));
	return (SUCCESS);
}
