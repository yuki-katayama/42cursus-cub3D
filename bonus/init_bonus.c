/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:39:16 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/01 13:28:02 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	ft_init03(t_sys *s, char *path)
{
	int i;
	int j;

	i = -1;
	while (++i < MAP_HEIGHT)
	{
		j = -1;
		while (++j < MAP_WIDTH)
			s->map.table[i][j] = '#';
		s->map.table[i][j] = '\0';
	}
	if (ft_parse(s, path) == -1)
		ft_close(s);
	s->dist_plane =
		(s->win.w / 2) / tan(s->player.a / 2);
	s->num_rays = s->win.w;
	if (!(s->rays = (t_ray *)malloc(sizeof(t_ray) * s->num_rays)))
	{
		ft_error(-36, 0);
		ft_close(s);
	}
	return (SUCCESS);
}

static void	ft_init02(t_sys *s)
{
	s->player.x = 0;
	s->player.y = 0;
	s->player.rot_a = 0;
	s->player.start_dir = '\0';
	s->player.side_dir = '\0';
	s->player.w = PLAYER_WIDTH;
	s->player.h = PLAYER_HEIGHT;
	s->player.turn_dir = 0;
	s->player.walk_dir = 0;
	s->player.walk_speed = WALK_SPEED;
	s->player.turn_speed = TURN_SPEED * (PI / 180);
	s->player.a = FOV * (PI / 180);
}

static void	ft_init01(t_sys *s)
{
	s->mlx.ptr = NULL;
	s->win.ptr = NULL;
	s->win.w = 0;
	s->win.h = 0;
	s->win.exist = 0;
	s->pixels.ptr = NULL;
	s->err = 0;
	s->map.rows = 0;
	s->map.cols = 0;
	s->map.max_cols = 0;
	s->map.num_spr = 0;
	s->spr = NULL;
	s->rays = NULL;
	s->tex.n.ptr = NULL;
	s->tex.s.ptr = NULL;
	s->tex.e.ptr = NULL;
	s->tex.w.ptr = NULL;
	s->tex.i.ptr = NULL;
	s->tex.f = -1;
	s->tex.c = -1;
}

int			ft_init(t_sys *s, char *path)
{
	ft_init01(s);
	ft_init02(s);
	if (ft_init03(s, path) == -1)
		return (FAILED);
	return (SUCCESS);
}
