/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:47:33 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/24 14:04:44 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

void		ft_render_map_sprites(t_sys *s)
{
	int	i;

	i = -1;
	while (++i < s->map.num_spr)
	{
		s->line.x = MINIMAP_SCALE_FACTOR * s->spr[i].x;
		s->line.y = MINIMAP_SCALE_FACTOR * s->spr[i].y;
		s->line.w = MINIMAP_SCALE_FACTOR * 2;
		s->line.h = MINIMAP_SCALE_FACTOR * 2;
		s->line.color = YELLOW;
		ft_draw_rectangle(
			&s->line,
			s);
	}
}

void		ft_render_map_rays(t_sys *s)
{
	int	i;

	i = 0;
	while (i < s->num_rays)
	{
		s->line.x = MINIMAP_SCALE_FACTOR * s->player.x;
		s->line.y = MINIMAP_SCALE_FACTOR * s->player.y;
		s->line.w = MINIMAP_SCALE_FACTOR * s->rays[i].hit_x;
		s->line.h = MINIMAP_SCALE_FACTOR * s->rays[i].hit_y;
		s->line.color = RED;
		ft_draw_line(
			&s->line,
			s);
		i += 100;
	}
}

void		ft_render_map_player(t_sys *s)
{
	s->line.x = MINIMAP_SCALE_FACTOR * (s->player.x - s->player.w / 2);
	s->line.y = MINIMAP_SCALE_FACTOR * (s->player.y - s->player.h / 2);
	s->line.w = MINIMAP_SCALE_FACTOR * MINIMAP_SCALE_FACTOR * s->player.w;
	s->line.h = MINIMAP_SCALE_FACTOR * s->player.h;
	s->line.color = RED;
	ft_draw_rectangle(
		&s->line,
		s);
}

void		ft_render_map_grid(t_sys *s)
{
	int		i;
	int		j;

	i = -1;
	while (++i < s->map.rows)
	{
		j = -1;
		while (++j < s->map.cols)
		{
			s->line.x = MINIMAP_SCALE_FACTOR * (j * TILE_SIZE);
			s->line.y = MINIMAP_SCALE_FACTOR * (i * TILE_SIZE);
			s->line.w = MINIMAP_SCALE_FACTOR * TILE_SIZE;
			s->line.h = MINIMAP_SCALE_FACTOR * TILE_SIZE;
			s->line.color = s->map.table[i][j] == '1' ? WHITE : BLACK;
			ft_draw_rectangle(
				&s->line,
				s);
		}
	}
}
