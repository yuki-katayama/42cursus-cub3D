/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:48:25 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/06 15:02:38 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_horz_ray_info(t_ray_tool *tool, t_sys *s)
{
	float	x_to_check;
	float	y_to_check;

	while (ft_is_inside_map(tool->next_x, tool->next_y, s))
	{
		x_to_check = tool->next_x;
		y_to_check = tool->next_y;
		if (s->hit.up == 1)
			y_to_check -= 1;
		if (ft_map_has_wall_at(x_to_check, y_to_check, s) == '1')
		{
			s->horz.hit_x = tool->next_x;
			s->horz.hit_y = tool->next_y;
			s->horz.texture = ft_get_map_at((int)floor(y_to_check / TILE_SIZE), \
										(int)floor(x_to_check / TILE_SIZE), s);
			tool->found_wall_hit = TRUE;
			break ;
		}
		else
		{
			tool->next_x += tool->xstep;
			tool->next_y += tool->ystep;
		}
	}
}

void	ft_ray_horizontal(float ray_a, t_sys *s)
{
	t_ray_tool	tool;

	tool.found_wall_hit = FALSE;
	s->horz.hit_x = 0;
	s->horz.hit_y = 0;
	tool.yitcept = floor(s->player.y / TILE_SIZE) * TILE_SIZE;
	if (s->hit.down == 1)
		tool.yitcept += TILE_SIZE;
	tool.xitcept = s->player.x + ((tool.yitcept - s->player.y) / tan(ray_a));
	tool.ystep = TILE_SIZE;
	if (s->hit.up == 1)
		tool.ystep *= -1;
	tool.xstep = TILE_SIZE / tan(ray_a);
	if (s->hit.left && tool.xstep > 0)
		tool.xstep *= -1;
	if (s->hit.right && tool.xstep < 0)
		tool.xstep *= -1;
	tool.next_x = tool.xitcept;
	tool.next_y = tool.yitcept;
	ft_set_horz_ray_info(&tool, s);
	if (tool.found_wall_hit == 1)
		s->horz.distance = \
			ft_distance(s->player.x, s->player.y, s->horz.hit_x, s->horz.hit_y);
	else
		s->horz.distance = FLT_MAX;
}
