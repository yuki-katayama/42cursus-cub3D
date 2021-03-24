/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:01:33 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/24 05:10:04 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

char		ft_map_has_wall_at(float x, float y, t_sys *s)
{
	int map_grid_index_x;
	int map_grid_index_y;

	map_grid_index_x = floor(x / TILE_SIZE);
	map_grid_index_y = floor(y / TILE_SIZE);
	if (x < 0 || x >= s->map.cols * TILE_SIZE
		|| y < 0 || y > s->map.rows * TILE_SIZE)
		return (TRUE);
	return (s->map.table[map_grid_index_y][map_grid_index_x]);
}

uint16_t	ft_is_inside_map(float x, float y, t_sys *s)
{
	return (x >= 0 && x <= s->map.cols * TILE_SIZE
			&& y >= 0 && y <= s->map.rows * TILE_SIZE);
}

char		ft_get_map_at(int i, int j, t_sys *s)
{
	return (s->map.table[i][j]);
}
