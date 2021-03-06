/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:24:45 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/08 12:36:14 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_player(t_sys *s)
{
	float	new_x;
	float	new_y;
	float	move_step;
	float	side;

	s->player.rot_a += s->player.turn_dir * s->player.turn_speed;
	ft_normalize_angle(&s->player.rot_a);
	move_step = s->player.walk_dir * s->player.walk_speed;
	new_x = 0.0;
	new_y = 0.0;
	side = 0;
	if (s->player.side_dir == 'S')
		side = PI / 2;
	new_x = s->player.x + cos(s->player.rot_a + side) * move_step;
	new_y = s->player.y + sin(s->player.rot_a + side) * move_step;
	if (ft_map_has_wall_at(new_x, new_y, s) == '0'
		|| ft_map_has_wall_at(new_x, new_y, s) == s->player.start_dir)
	{
		s->player.x = new_x;
		s->player.y = new_y;
	}
}
