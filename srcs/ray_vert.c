/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:47:48 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/06 14:32:31 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_vert_ray_info(t_ray_tool *tool, t_sys *s)
{
	float		x_to_check;
	float		y_to_check;

	while (ft_is_inside_map(tool->next_x, tool->next_y, s))
	{
		x_to_check = tool->next_x;
		y_to_check = tool->next_y;
		if (s->hit.left == 1)
			x_to_check -= 1;
		if (ft_map_has_wall_at(x_to_check, y_to_check, s) == '1')
		{
			s->vert.hit_x = tool->next_x;
			s->vert.hit_y = tool->next_y;
			s->vert.texture = ft_get_map_at((int)floor(y_to_check / TILE_SIZE), \
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

void	ft_ray_vertical(float ray_a, t_sys *s)
{
	t_ray_tool	tool;

	tool.found_wall_hit = FALSE;
	s->vert.hit_x = 0;
	s->vert.hit_y = 0;
	tool.xitcept = floor(s->player.x / TILE_SIZE) * TILE_SIZE;
	if (s->hit.right == 1)
		tool.xitcept += TILE_SIZE;
	tool.yitcept = s->player.y + (tool.xitcept - s->player.x) * tan(ray_a);
	tool.xstep = TILE_SIZE;
	if (s->hit.left == 1)
		tool.xstep *= -1;
	tool.ystep = TILE_SIZE * tan(ray_a);
	if (s->hit.up && tool.ystep > 0)
		tool.ystep *= -1;
	if (s->hit.down && tool.ystep < 0)
		tool.ystep *= -1;
	tool.next_x = tool.xitcept;
	tool.next_y = tool.yitcept;
	ft_set_vert_ray_info(&tool, s);
	if (tool.found_wall_hit == 1)
		s->vert.distance = \
			ft_distance(s->player.x, s->player.y, s->vert.hit_x, s->vert.hit_y);
	else
		s->vert.distance = FLT_MAX;
}
