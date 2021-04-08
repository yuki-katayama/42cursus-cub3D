/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:08:32 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/08 18:32:14 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_map_rows(char *path, t_sys *s)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	fd = open(path, O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		s->map.max_rows++;
		free(line);
	}
	close(fd);
}

static int	ft_parse_rows(int fd, t_sys *s)
{
	int		ret;
	int		row;
	char	*line;

	row = 0;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			ft_error(-37, -1);
			break ;
		}
		if (ft_check_line(s, line, ++row) == -1)
			ret = -1;
		free(line);
	}
	s->map.rows++;
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	close(fd);
	return (ret);
}

int	ft_parse(t_sys *s, char *path)
{
	int		fd;
	int		ret;

	get_map_rows(path, s);
	fd = open(path, O_RDONLY);
	if (fd == -1 || ft_strchr(path, '/') == NULL || !ft_strchr(path, '/')[1])
		return (ft_error(-4, -1));
	ret = ft_parse_rows(fd, s);
	if (ret == -1)
		return (FAILED);
	if (ft_create_spr_list(s) == -1)
		return (FAILED);
	if (ft_check_all(s) == -1)
		return (FAILED);
	s->map.cols = s->map.max_cols;
	if (s->bmp == 0)
		ft_create_window(s);
	ft_create_pixels(s);
	return (SUCCESS);
}
