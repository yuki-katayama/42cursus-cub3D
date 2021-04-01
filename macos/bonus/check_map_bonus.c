/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:54:00 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/01 13:16:14 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	ft_check_surd_wall(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '*')
		return (TRUE);
	if (x + 1 >= MAP_WIDTH || y + 1 >= MAP_HEIGHT
			|| x - 1 <= -1 || y - 1 <= -1)
		return (FALSE);
	map[y][x] = '*';
	if (map[y][x + 1] == '#')
		return (FALSE);
	if (map[y][x - 1] == '#')
		return (FALSE);
	if (map[y + 1][x] == '#')
		return (FALSE);
	if (map[y - 1][x] == '#')
		return (FALSE);
	return (ft_check_surd_wall(map, x, y + 1)
			&& ft_check_surd_wall(map, x, y - 1)
			&& ft_check_surd_wall(map, x + 1, y)
			&& ft_check_surd_wall(map, x - 1, y));
}

static void	ft_free_tmp(char **tmp, int j)
{
	int	i;

	i = -1;
	while (++i < j)
		free(tmp[i]);
	free(tmp);
}

int			ft_check_map(t_sys *s)
{
	int		i;
	char	**tmp;

	if (!(tmp = malloc(sizeof(char *) * (MAP_HEIGHT))))
	{
		free(tmp);
		return (FAILED - 1);
	}
	i = -1;
	while (++i < MAP_HEIGHT)
	{
		if (!(tmp[i] = malloc(sizeof(char) * (MAP_WIDTH))))
		{
			ft_free_tmp(tmp, i + 1);
			return (FAILED - 1);
		}
		ft_memcpy(tmp[i], s->map.table[i], MAP_WIDTH);
	}
	if (ft_check_surd_wall(tmp, s->player.x / TILE_SIZE,
								s->player.y / TILE_SIZE) == 0)
		s->err = FAILED;
	ft_free_tmp(tmp, MAP_HEIGHT);
	return ((s->err == FAILED) ? s->err : SUCCESS);
}
