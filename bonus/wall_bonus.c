/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:39:39 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/31 20:35:46 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void		ft_change_color_intensity(uint32_t *color, float factor)
{
	uint32_t r;
	uint32_t g;
	uint32_t b;

	r = (*color / 256 / 256) * factor;
	g = (*color / 256 % 256) * factor;
	b = (*color % 256) * factor;
	*color = (r * 256 * 256) + (g * 256) + b;
}

static void		ft_set_wall_info(int x, t_wall_tool *tool, t_sys *s)
{
	tool->perp_distance =
		s->rays[x].distance * cos(s->rays[x].ray_a - s->player.rot_a);
	tool->wall_h = (TILE_SIZE / tool->perp_distance) * s->dist_plane;
	tool->wall_top_y = (s->win.h / 2) - (tool->wall_h / 2);
	tool->wall_top_y = tool->wall_top_y < 0 ? 0 : tool->wall_top_y;
	tool->wall_bottom_y = (s->win.h / 2) + (tool->wall_h / 2);
	tool->wall_bottom_y = tool->wall_bottom_y > s->win.h
							? s->win.h : tool->wall_bottom_y;
	if (s->rays[x].was_hit_vertical)
		tool->tex_ofs_x = (int)s->rays[x].hit_y % TILE_SIZE;
	else
		tool->tex_ofs_x = (int)s->rays[x].hit_x % TILE_SIZE;
	tool->tex_w = s->tex.width;
	tool->tex_h = s->tex.height;
}

static void		ft_set_tex_to_wall(int x, int y, t_wall_tool *tool, t_sys *s)
{
	tool->fr_top = y + (tool->wall_h / 2) - (s->win.h / 2);
	tool->tex_ofs_y = tool->fr_top * ((float)tool->tex_h / tool->wall_h);
	tool->texel_color = 0;
	if (s->rays[x].was_hit_vertical)
	{
		if (s->rays[x].was_hit_east == TRUE)
			tool->texel_color =
				s->tex.e.buf[(tool->tex_w * tool->tex_ofs_y) + tool->tex_ofs_x];
		else
			tool->texel_color =
				s->tex.w.buf[(tool->tex_w * tool->tex_ofs_y) + tool->tex_ofs_x];
	}
	else
	{
		if (s->rays[x].was_hit_north == TRUE)
			tool->texel_color =
				s->tex.n.buf[(tool->tex_w * tool->tex_ofs_y) + tool->tex_ofs_x];
		else
			tool->texel_color =
				s->tex.s.buf[(tool->tex_w * tool->tex_ofs_y) + tool->tex_ofs_x];
	}
	if (s->rays[x].was_hit_vertical)
		ft_change_color_intensity(&tool->texel_color, VERT_INTENSITY);
	else
		ft_change_color_intensity(&tool->texel_color, HORZ_INTENSITY);
}

void			ft_render_wall_projection(t_sys *s)
{
	t_wall_tool	tool;
	int			x;
	int			y;

	x = -1;
	while (++x < s->num_rays)
	{
		ft_set_wall_info(x, &tool, s);
		y = -1;
		while (++y < tool.wall_top_y)
			ft_draw_pixel(x, y, s->tex.c, s);
		y = tool.wall_top_y - 1;
		while (++y < tool.wall_bottom_y)
		{
			ft_set_tex_to_wall(x, y, &tool, s);
			ft_draw_pixel(x, y, tool.texel_color, s);
		}
		y = tool.wall_bottom_y - 1;
		while (++y < s->win.h)
			ft_draw_pixel(x, y, s->tex.f, s);
	}
}
