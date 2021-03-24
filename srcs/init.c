/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:39:16 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/25 00:10:05 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static void	ft_init02(t_sys *s)
{
	s->player.side_dir = '\0';
	s->player.w = PLAYER_WIDTH;
	s->player.h = PLAYER_HEIGHT;
	s->player.turn_dir = 0;
	s->player.walk_dir = 0;
	s->player.walk_speed = WALK_SPEED;
	s->player.turn_speed = TURN_SPEED * (PI / 180);
	s->player.a = FOV * (PI / 180);
	s->dist_plane =
		(s->win.w / 2) / tan(s->player.a / 2);
	s->num_rays = s->win.w;
	s->rays = (t_ray *)malloc(sizeof(t_ray) * s->num_rays);
}

static void ft_all_free(t_sys *s)
{
	if(s->win.exist == 1)
	{
		ft_destroy_window(s);
		ft_destroy_pixels(s);
		ft_destroy_mlx(s);
	}
	while(1){}
}

static int	ft_init01(t_sys *s, char *path)
{
	s->err = 0;
	s->win.w = 0;
	s->win.h = 0;
	s->win.exist = 0;
	s->tex.n = NULL;
	s->tex.s = NULL;
	s->tex.e = NULL;
	s->tex.w = NULL;
	s->tex.i = NULL;
	s->tex.f = -1;
	s->tex.c = -1;
	s->map.table = NULL;
	s->map.rows = 0;
	s->map.cols = 0;
	s->map.num_spr = 0;
	s->player.x = 0;
	s->player.y = 0;
	s->player.rot_a = 0;
	s->player.start_dir = '\0';
	s->spr = NULL;
	s->rays = NULL;
	if (ft_parse(s, path) == -1)
	{
		ft_all_free(s);
		return (FAILED);
	}
	return (SUCCESS);
}

int		ft_init(t_sys *s, char *path)
{
	if(ft_init01(s, path) == -1)
		return (FAILED);
	ft_init02(s);
	return (SUCCESS);
}
