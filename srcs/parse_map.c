/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:01:39 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/23 19:16:01 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static int		ft_judge_map_params(t_sys *s, int y)
{
	int	x;
	int	count;

	count = 0;
	x = -1;
	while (s->map.table[y][++x] != '\0')
	{
		if (s->map.table[y][x] == '0' || s->map.table[y][x] == '1'
			|| s->map.table[y][x] == '2' || s->map.table[y][x] == ' ')
		{
			if (s->map.table[y][x] == '2')
				s->map.num_spr++;
			count++;
		}
		else if (s->map.table[y][x] == 'N' || s->map.table[y][x] == 'S'
				|| s->map.table[y][x] == 'E' || s->map.table[y][x] == 'W')
		{
			if (ft_set_player(s, x, y, s->map.table[y][x]) == -1)
				return (FAILED + -1);
			count++;
		}
	}
	if (s->map.cols != count)
		return (FAILED);
	return (SUCCESS);
}

static char		*ft_malloc_cols(t_sys *s, char *line, int *i)
{
	char	*tmp;
	int		j;

	if (!(tmp = (char *)malloc(sizeof(char) * (s->map.cols + 1))))
		return (NULL);
	j = 0;
	while (line[*i] != '\0')
	{
		if (line[*i] == ' ')
			tmp[j++] = '1';
		else
			tmp[j++] = line[*i];
		(*i)++;
	}
	while (j < s->map.cols)
		tmp[j++] = '1';
	tmp[j] = '\0';
	return (tmp);
}

int				ft_set_map(t_sys *s, char *line, int *i)
{
	char	**tmp;
	int		j;

	if (!(tmp = (char **)malloc(sizeof(char *) * (s->map.rows + 2))))
		return (-21);
	j = -1;
	while (++j < s->map.rows)
		tmp[j] = s->map.table[j];
	if ((tmp[j] = ft_malloc_cols(s, line, i)) == NULL)
		return (-21);
	tmp[s->map.rows + 1] = NULL;
	if (s->map.rows > 0)
		free(s->map.table);
	s->map.table = tmp;
	if ((s->err = ft_judge_map_params(s, s->map.rows)) < 0)
	{
		if (s->err == -1)
			return (-22);
		else if (s->err == -2)
			return (-24);
	}
	s->map.rows++;
	return (SUCCESS);
}
