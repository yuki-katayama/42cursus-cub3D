/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 03:22:14 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/01 03:22:30 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_render(t_sys *s)
{
	ft_clear_color_buffer(WHITE, s);
	ft_render_wall_projection(s);
	ft_render_sprite_projection(s);
	ft_render_color_buffer(s);
}

static void	ft_update(t_sys *s)
{
	ft_move_player(s);
	ft_cast_all_rays(s);
}

static int	ft_loop(t_sys *s)
{
	ft_update(s);
	ft_render(s);
	return (SUCCESS);
}

int			main(int argc, char **argv)
{
	t_sys	s;

	if ((argc == 2) || (argc == 3 && ft_strcmp(argv[2], "--save") == 0))
	{
		s.bmp = 1;
		if (argc == 3)
			s.bmp = 0;
		if (ft_init(&s, argv[1]) == -1)
			return (EXIT);
		if (argc == 3)
		{
			ft_bitmap(&s);
			return (EXIT);
		}
		mlx_hook(s.win.ptr, 17, 1L << 17, ft_close, &s);
		mlx_hook(s.win.ptr, 2, 1L << 0, ft_press_key, &s);
		mlx_hook(s.win.ptr, 3, 1L << 1, ft_release_key, &s);
		mlx_loop_hook(s.mlx.ptr, &ft_loop, &s);
		mlx_loop(s.mlx.ptr);
	}
	else
		return (ft_error(-26, -1));
	return (EXIT);
}
