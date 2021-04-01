/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:01:54 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/31 13:21:34 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_set_player(t_sys *s, int x, int y, char c)
{
	if (s->player.num_player == 1)
		return (FAILED);
	s->player.x = ((TILE_SIZE * x) + (TILE_SIZE / 2));
	s->player.y = ((TILE_SIZE * y) + (TILE_SIZE / 2));
	s->player.rot_a += (c == 'S') ? PI / 2 : 0;
	s->player.rot_a += (c == 'W') ? PI : 0;
	s->player.rot_a += (c == 'N') ? (PI / 2) + PI : 0;
	s->player.num_player = 1;
	s->player.start_dir = c;
	return (SUCCESS);
}
