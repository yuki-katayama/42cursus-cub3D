/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:27:55 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/12 15:17:06 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_normalize_angle(float *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

float	ft_distance(float x1, float y1, float x2, float y2)
{
	return (ft_sqrt((x2 - x1) * (x2 - x1) + \
				(y2 - y1) * (y2 - y1)));
}

static int	ft_pre_process(const char *str, int *i, int *negative)
{
	ft_spaceskip(str, i);
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*negative = *negative * -1;
		(*i)++;
	}
	if (str[*i] == '0' && str[*i + 1] >='0' && str[*i] <= '9')
		return (-1);
	return (0);
}

int	ft_atoi(const char *str, int *i)
{
	unsigned long long	output;
	int					negative;
	int					keta;

	keta = -1;
	output = 0;
	negative = 1;
	if (ft_pre_process(str, i, &negative) == -1)
		return (-1);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (++keta < 7)
			output = output * 10 + str[*i] - 48;
		(*i)++;
		if (output > 9223372036854775807 && negative == -1)
			return (0);
		if (output > 9223372036854775806 && negative == 1)
			return (-1);
	}
	return ((int)output * negative);
}
