/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:01:54 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/25 00:26:09 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_set_player(t_sys *s, int x, int y, char c)
{
	if (s->player.num_player == 1)
		return (FAILED);
	s->player.x = ((TILE_SIZE * x) + (TILE_SIZE / 2) + 0.01);
	s->player.y = ((TILE_SIZE * y) + (TILE_SIZE / 2) + 0.01);
	if (c == 'S')
		s->player.rot_a += PI / 2;
	else if (c == 'W')
		s->player.rot_a += PI;
	else if (c == 'N')
		s->player.rot_a += PI / 2 + PI;
	s->player.num_player = 1;
	s->player.start_dir = c;
	return (SUCCESS);
}
