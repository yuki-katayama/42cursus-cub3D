/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:35:12 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/31 13:21:34 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_find_visible_sprites(int *num_visi_sprs,
											t_sprite *visi_sprs, t_sys *s)
{
	float	epsilon;
	float	a_spr_pl;
	int		i;

	i = -1;
	while (++i < s->map.num_spr)
	{
		a_spr_pl = s->player.rot_a -
					atan2(s->spr[i].y - s->player.y, s->spr[i].x - s->player.x);
		a_spr_pl = (a_spr_pl > PI) ? a_spr_pl - TWO_PI : a_spr_pl;
		a_spr_pl = (a_spr_pl < -PI) ? a_spr_pl + TWO_PI : a_spr_pl;
		a_spr_pl = fabs(a_spr_pl);
		epsilon = 0.3;
		if (a_spr_pl < (s->player.a / 2) + epsilon)
		{
			s->spr[i].visible = TRUE;
			s->spr[i].a = a_spr_pl;
			s->spr[i].distance =
				ft_distance(s->spr[i].x, s->spr[i].y, s->player.x, s->player.y);
			visi_sprs[*num_visi_sprs] = s->spr[i];
			(*num_visi_sprs)++;
		}
		else
			s->spr[i].visible = FALSE;
	}
}

static void		ft_sort_sprites(int num_visi_sprs, t_sprite *visi_sprs)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = -1;
	while (++i < num_visi_sprs)
	{
		j = i;
		while (++j < num_visi_sprs)
		{
			if (visi_sprs[i].distance < visi_sprs[j].distance)
			{
				tmp = visi_sprs[i];
				visi_sprs[i] = visi_sprs[j];
				visi_sprs[j] = tmp;
			}
		}
	}
}

static void		ft_set_sprite_info(t_sprite_tool *tool, t_sprite spr, t_sys *s)
{
	tool->perp_distance = spr.distance * cos(spr.a);
	tool->h = (TILE_SIZE / tool->perp_distance) * s->dist_plane;
	tool->w = tool->h;
	tool->top_y = (s->win.h / 2) - (tool->h / 2);
	tool->top_y = (tool->top_y < 0) ? 0 : tool->top_y;
	tool->bottom_y = (s->win.h / 2) + (tool->h / 2);
	tool->bottom_y = (tool->bottom_y > s->win.h)
						? s->win.h
						: tool->bottom_y;
	tool->angle =
		atan2(spr.y - s->player.y, spr.x - s->player.x) - s->player.rot_a;
	tool->screen_pos_x = tan(tool->angle) * s->dist_plane;
	tool->left_x = ((s->win.w / 2) + tool->screen_pos_x) - (tool->w / 2);
	tool->right_x = tool->left_x + tool->w;
	tool->tex_w = s->tex.width;
	tool->tex_h = s->tex.height;
}

static void		ft_draw_sprite(t_sprite_tool *tool, t_sprite spr, t_sys *s)
{
	int x;
	int y;

	x = tool->left_x;
	while (++x < tool->right_x)
	{
		tool->texel_w = (tool->tex_w / tool->w);
		tool->tex_ofs_x = (x - tool->left_x) * tool->texel_w;
		y = tool->top_y;
		while (++y < tool->bottom_y)
		{
			if (x > 0 && x < s->win.w && y > 0 && y < s->win.h)
			{
				tool->distance_from_top =
					y + (tool->h / 2) - (s->win.h / 2);
				tool->tex_ofs_y =
					tool->distance_from_top * (tool->tex_h / tool->h);
				tool->buff = s->tex.i.buf;
				tool->c =
				tool->buff[(tool->tex_w * tool->tex_ofs_y) + tool->tex_ofs_x];
				if (spr.distance < s->rays[x].distance && tool->c != 0x000000)
					ft_draw_pixel(x, y, tool->c, s);
			}
		}
	}
}

void			ft_render_sprite_projection(t_sys *s)
{
	t_sprite		visi_sprs[s->map.num_spr];
	t_sprite		spr;
	t_sprite_tool	tool;
	int				num_visi_sprs;
	int				i;

	num_visi_sprs = 0;
	ft_find_visible_sprites(&num_visi_sprs, visi_sprs, s);
	ft_sort_sprites(num_visi_sprs, visi_sprs);
	i = -1;
	while (++i < num_visi_sprs)
	{
		spr = visi_sprs[i];
		ft_set_sprite_info(&tool, spr, s);
		ft_draw_sprite(&tool, spr, s);
	}
}
