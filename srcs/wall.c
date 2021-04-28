#include "cub3d.h"

static void	ft_change_color_intensity(uint32_t *color, float factor)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = (*color / 256 / 256) * factor;
	g = (*color / 256 % 256) * factor;
	b = (*color % 256) * factor;
	*color = (r * 256 * 256) + (g * 256) + b;
}

static void	ft_set_wall_info(int x, t_wall_tool *tool, t_sys *s)
{
	tool->perp_distance = \
		s->rays[x].distance * cos(s->rays[x].ray_a - s->player.rot_a);
	tool->wall_h = (TILE_SIZE / tool->perp_distance) * s->dist_plane;
	tool->wall_top_y = (s->win.h / 2) - (tool->wall_h / 2);
	if (tool->wall_top_y < 0)
		tool->wall_top_y = 0;
	tool->wall_bottom_y = (s->win.h / 2) + (tool->wall_h / 2);
	if (tool->wall_bottom_y > s->win.h)
		tool->wall_bottom_y = s->win.h;
}

void	ft_render_wall_projection(t_sys *s)
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
			if (s->rays[x].was_hit_vertical)
				ft_change_color_intensity(&tool.texel_color, VERT_INTENSITY);
			else
				ft_change_color_intensity(&tool.texel_color, HORZ_INTENSITY);
			ft_draw_pixel(x, y, tool.texel_color, s);
		}
		y = tool.wall_bottom_y - 1;
		while (++y < s->win.h)
			ft_draw_pixel(x, y, s->tex.f, s);
	}
}
