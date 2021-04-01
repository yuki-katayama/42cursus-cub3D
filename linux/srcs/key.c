/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:01:08 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/31 13:21:34 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_data(int keycode, int set, t_sys *s)
{
	if (keycode == KEY_W)
		s->player.walk_dir = set;
	else if (keycode == KEY_S)
		s->player.walk_dir = set * -1;
	else if (keycode == KEY_D)
	{
		s->player.side_dir = 'S';
		s->player.walk_dir = set;
	}
	else if (keycode == KEY_A)
	{
		s->player.side_dir = 'S';
		s->player.walk_dir = set * -1;
	}
	else if (keycode == KEY_RIGHT)
		s->player.turn_dir = set;
	else if (keycode == KEY_LEFT)
		s->player.turn_dir = set * -1;
}

static void	ft_set_keys_param(int keycode, int set, t_sys *s)
{
	if (keycode == KEY_ESC)
		ft_close(s);
	else
		ft_set_data(keycode, set, s);
}

int			ft_press_key(int keycode, t_sys *s)
{
	ft_set_keys_param(keycode, 1, s);
	return (1);
}

int			ft_release_key(int keycode, t_sys *s)
{
	ft_set_keys_param(keycode, 0, s);
	return (1);
}
