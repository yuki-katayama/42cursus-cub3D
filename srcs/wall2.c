#include "cub3d.h"

static void	ft_set_tex_ofs_x(int x, t_wall_tool *tool, t_sys *s, t_pixel tex)
{
	if (s->rays[x].was_hit_vertical)
		tool->tex_ofs_x = ((int)s->rays[x].hit_y % TILE_SIZE) \
			* (tex.width / (double)TILE_SIZE);
	else
		tool->tex_ofs_x = ((int)s->rays[x].hit_x % TILE_SIZE) \
			* (tex.width / (double)TILE_SIZE);
}

static void	ft_set_tex_ofs_y(int y, t_wall_tool *tool, t_sys *s, t_pixel tex)
{
	tool->tex_w = tex.width;
	tool->tex_h = tex.height;
	tool->fr_top = y + (tool->wall_h / 2) - (s->win.h / 2);
	tool->tex_ofs_y = tool->fr_top * ((float)tool->tex_h / tool->wall_h);
}

static void	ft_set_color_e_or_w(int x, int y, t_wall_tool *tool, t_sys *s)
{
	if (s->rays[x].was_hit_east == TRUE)
	{
		ft_set_tex_ofs_x(x, tool, s, s->tex.e);
		ft_set_tex_ofs_y(y, tool, s, s->tex.e);
		tool->texel_color = \
			s->tex.e.buf[(tool->tex_w * tool->tex_ofs_y) + tool->tex_ofs_x];
	}
	else
	{
		ft_set_tex_ofs_x(x, tool, s, s->tex.w);
		ft_set_tex_ofs_y(y, tool, s, s->tex.w);
		tool->texel_color = \
			s->tex.w.buf[(tool->tex_w * tool->tex_ofs_y) + tool->tex_ofs_x];
	}
}

static void	ft_set_color_n_or_s(int x, int y, t_wall_tool *tool, t_sys *s)
{
	if (s->rays[x].was_hit_north == TRUE)
	{
		ft_set_tex_ofs_x(x, tool, s, s->tex.n);
		ft_set_tex_ofs_y(y, tool, s, s->tex.n);
		tool->texel_color = \
			s->tex.n.buf[(tool->tex_w * tool->tex_ofs_y) + tool->tex_ofs_x];
	}
	else
	{
		ft_set_tex_ofs_x(x, tool, s, s->tex.s);
		ft_set_tex_ofs_y(y, tool, s, s->tex.s);
		tool->texel_color = \
			s->tex.s.buf[(tool->tex_w * tool->tex_ofs_y) + tool->tex_ofs_x];
	}
}

void	ft_set_tex_to_wall(int x, int y, t_wall_tool *tool, t_sys *s)
{
	tool->texel_color = 0;
	if (s->rays[x].was_hit_vertical)
		ft_set_color_e_or_w(x, y, tool, s);
	else
		ft_set_color_n_or_s(x, y, tool, s);
}
