/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:01:36 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/31 20:35:15 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int32_t		ft_set_color(char *line, int *i)
{
	int32_t color;

	color = ft_atoi(line, i);
	if (ft_haschar(&line[*i], ',') == -1)
		return (-18);
	ft_spaceskip(line, i);
	(*i)++;
	return (color);
}

int					ft_set_colors(int *color, char *line, int *i)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;

	if (*color != -1)
		return (-29);
	(*i)++;
	ft_spaceskip(line, i);
	if ((r = ft_set_color(line, i)) < 0)
		return (r);
	if ((g = ft_set_color(line, i)) < 0)
		return (g);
	ft_spaceskip(line, i);
	if (ft_isdigit(line[*i]) == -1)
		return (-18);
	b = ft_atoi(line, i);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-17);
	else if (line[*i] != '\0')
		return (-19);
	*color = (uint32_t)(r * 256 * 256) + (g * 256) + (b);
	return (SUCCESS);
}
