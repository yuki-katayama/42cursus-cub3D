/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:27:55 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/31 20:35:43 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_normalize_angle(float *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

float	ft_distance(float x1, float y1, float x2, float y2)
{
	return (ft_sqrt((x2 - x1) * (x2 - x1) +
				(y2 - y1) * (y2 - y1)));
}
