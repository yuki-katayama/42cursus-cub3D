/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:20:32 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/24 18:53:43 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static int			ft_check_line01(t_sys *s, char *line, int *i)
{
	if (line[0] == 'R' && line[1] == ' ')
		s->err = ft_set_win(s, line, i);
	else if (s->win.w <= 0 || s->win.h <= 0)
		s->err = -13;
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		s->err = ft_set_tex(s, &s->tex.n, line, i);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		s->err = ft_set_tex(s, &s->tex.s, line, i);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		s->err = ft_set_tex(s, &s->tex.w, line, i);
	return (s->err < 0 ? -1 : SUCCESS);
}

static void			ft_check_line02(t_sys *s, char *line, int *i)
{
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		s->err = ft_set_tex(s, &s->tex.e, line, i);
	else if (line[0] == 'S' && line[1] == ' ')
		s->err = ft_set_tex(s, &s->tex.i, line, i);
	else if (line[0] == 'F' && line[1] == ' ')
		s->err = ft_set_colors(&s->tex.f, line, i);
	else if (line[0] == 'C' && line[1] == ' ')
		s->err = ft_set_colors(&s->tex.c, line, i);
	else if (line[0] == '1' || line[0] == ' ' || line[0] == '0')
		s->err = ft_set_map(s, line, i);
}

int					ft_check_line(t_sys *s, char *line, int row)
{
	int i;

	i = 0;
	if (ft_check_line01(s, line, &i) == 0)
		ft_check_line02(s, line, &i);
	if (ft_spaceskip(line, &i) && s->err == 0 && line[i] != '\0')
		s->err = -3;
	return (s->err < 0 ? ft_error(s->err, row) : SUCCESS);
}

int					ft_check_surd_wall(t_sys *s)
{
	int x;
	int y;

	x = -1;
	while (++x < s->map.cols)
	{
		y = -1;
		while (++y < s->map.rows)
		{
			if ((x == 0 || x == s->map.cols - 1) && s->map.table[y][x] != '1')
				return (FAILED);
			else if (s->map.table[y][x] != '1'
						&& (y == 0 || y == s->map.rows - 1))
				return (FAILED);
		}
	}
	return (SUCCESS);
}

int					ft_check_all(t_sys *s)
{
	if (s->tex.n == NULL)
		s->err = -9;
	else if (s->tex.s == NULL)
		s->err = -10;
	else if (s->tex.w == NULL)
		s->err = -11;
	else if (s->tex.e == NULL)
		s->err = -12;
	else if (s->tex.i == NULL)
		s->err = -30;
	else if (s->player.x == 0 && s->player.y == 0)
		s->err = -23;
	else if (ft_check_surd_wall(s))
		s->err = -25;
	return (s->err < 0 ? ft_error(s->err, NAN) : SUCCESS);
}
