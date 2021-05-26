/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:03:12 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/12 19:03:13 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_judge_simple_param(t_sys *s, int x, char *line)
{
	if (line[x] == '0' || line[x] == '1' \
			|| line[x] == '2' || line[x] == ' ' \
			|| line[x] == '#')
	{
		if (line[x] == '2')
			s->map.num_spr++;
		return (SUCCESS);
	}
	return (FAILED);
}

static int	ft_judge_player_param(int x, char *line)
{
	if (line[x] == 'N' || line[x] == 'S' \
			|| line[x] == 'E' || line[x] == 'W')
		return (SUCCESS);
	return (FAILED);
}

static int	ft_judge_map_params(t_sys *s, char *line, int y)
{
	int	x;
	int	count;

	count = 0;
	s->map.cols = 0;
	x = -1;
	while (line[++x] != '\0')
		s->map.cols++;
	if (s->map.cols > MAP_WIDTH)
		return (FAILED - 2);
	x = -1;
	while (line[++x] != '\0')
	{
		if (ft_judge_simple_param(s, x, line) == 0)
			count++;
		else if (ft_judge_player_param(x, line) == 0)
		{
			if (ft_set_player(s, x, y, line[x]) == -1)
				return (FAILED - 1);
			count++;
		}
	}
	if (s->map.cols != count)
		return (FAILED);
	return (SUCCESS);
}

void	ft_set_data(t_sys *s, char *line, int *i, int *j)
{
	if (line[*i] == ' ')
		s->map.table[s->map.rows][++(*j)] = '#';
	else if (line[*i] == '0')
		s->map.table[s->map.rows][++(*j)] = '*';
	else
		s->map.table[s->map.rows][++(*j)] = line[*i];
	(*i)++;
}

int	ft_set_map(t_sys *s, char *line, int *i)
{
	int	j;

	j = -1;
	while (line[++j])
	{
		if (line[j] == '#')
			return (-22);
	}
	if (line[*i] == '\0')
		return (-22);
	if (++(s->map.rows) >= MAP_HEIGHT)
		return (-35);
	s->err = ft_judge_map_params(s, line, s->map.rows);
	if (s->err < 0)
	{
		if (s->err == -1)
			return (-22);
		else if (s->err == -2)
			return (-24);
		return (-34);
	}
	j = -1;
	while (line[*i] != '\0')
		ft_set_data(s, line, i, &j);
	return (SUCCESS);
}
