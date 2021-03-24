/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:25:40 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/24 06:09:32 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static void		ft_set_info(float ray_a, int strip_id, t_sys *s)
{
	s->rays[strip_id].ray_a = ray_a;
	if (s->horz.distance > s->vert.distance)
	{
		s->rays[strip_id].distance = s->vert.distance;
		s->rays[strip_id].hit_x = s->vert.hit_x;
		s->rays[strip_id].hit_y = s->vert.hit_y;
		s->rays[strip_id].texture = s->vert.texture;
		s->rays[strip_id].was_hit_vertical = TRUE;
		if (s->hit.left)
			s->rays[strip_id].was_hit_east = TRUE;
		else
			s->rays[strip_id].was_hit_east = FALSE;
	}
	else
	{
		s->rays[strip_id].distance = s->horz.distance;
		s->rays[strip_id].hit_x = s->horz.hit_x;
		s->rays[strip_id].hit_y = s->horz.hit_y;
		s->rays[strip_id].texture = s->horz.texture;
		s->rays[strip_id].was_hit_vertical = FALSE;
		if (s->hit.down)
			s->rays[strip_id].was_hit_north = TRUE;
		else
			s->rays[strip_id].was_hit_north = FALSE;
	}
}

static void		ft_cast_ray(float ray_a, int strip_id, t_sys *s)
{
	ft_normalize_angle(&ray_a);
	s->hit.down = ray_a > 0 && ray_a < PI;
	s->hit.up = !s->hit.down;
	s->hit.right = ray_a < 0.5 * PI || ray_a > 1.5 * PI;
	s->hit.left = !s->hit.right;
	ft_ray_horizontal(ray_a, s);
	ft_ray_vertical(ray_a, s);
	ft_set_info(ray_a, strip_id, s);
}

void			ft_cast_all_rays(t_sys *s)
{
	int		col;
	float	ray_a;

	col = -1;
	while (++col < s->num_rays)
	{
		ray_a = s->player.rot_a + atan((col - s->num_rays / 2) / s->dist_plane);
		ft_cast_ray(ray_a, col, s);
	}
}
