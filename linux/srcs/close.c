/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:29:38 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/01 03:02:25 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_all_free(t_sys *s)
{
	if (s->win.ptr)
		mlx_destroy_window(s->mlx.ptr, s->win.ptr);
	if (s->tex.i.ptr)
		mlx_destroy_image(s->mlx.ptr, s->tex.i.ptr);
	if (s->tex.n.ptr)
		mlx_destroy_image(s->mlx.ptr, s->tex.n.ptr);
	if (s->tex.s.ptr)
		mlx_destroy_image(s->mlx.ptr, s->tex.s.ptr);
	if (s->tex.w.ptr)
		mlx_destroy_image(s->mlx.ptr, s->tex.w.ptr);
	if (s->tex.e.ptr)
		mlx_destroy_image(s->mlx.ptr, s->tex.e.ptr);
	if (s->pixels.ptr)
		mlx_destroy_image(s->mlx.ptr, s->pixels.ptr);
	if (s->mlx.ptr)
	{
		mlx_destroy_display(s->mlx.ptr);
		free(s->mlx.ptr);
	}
	if (s->rays)
		free(s->rays);
	if (s->spr)
		free(s->spr);
}

int				ft_close(t_sys *s)
{
	ft_all_free(s);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
