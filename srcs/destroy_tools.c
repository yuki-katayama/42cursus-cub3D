/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 02:35:28 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/25 00:25:13 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

void	ft_destroy_window(t_sys *s)
{
	mlx_destroy_window(s->mlx.ptr, s->win.ptr);
}

void ft_destroy_mlx(t_sys * s)
{
	free(s->mlx.ptr);
}

void	ft_destroy_pixels(t_sys *s)
{
	free(s->pixels.pix_buf);
	mlx_destroy_image(s->mlx.ptr, s->pixels.ptr);
}

void	ft_destroy_rays(t_sys *s)
{
	free(s->rays);
}
