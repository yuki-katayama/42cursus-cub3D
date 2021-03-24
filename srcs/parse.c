/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:08:32 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/24 19:34:10 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static int		ft_get_max_cols(t_sys *s, int fd)
{
	char	*line;
	int		ret;
	int		max;
	int		map_start;

	ret = 1;
	map_start = 0;
	while (ret == 1)
	{
		max = 0;
		ret = get_next_line(fd, &line);
		while (line[max] != '\0' && map_start == 1)
			max++;
		free(line);
		if (s->map.cols < max || s->map.cols == 0)
			s->map.cols = max;
		if (line[0] == 'C')
			map_start = 1;
	}
	return (SUCCESS);
}

int				ft_parse(t_sys *s, char *path)
{
	char	*line;
	int		fd;
	int		ret;
	int		row;

	fd = open(path, O_RDONLY);
	if (fd == -1 || ft_strchr(path, '/') == NULL || !ft_strchr(path, '/')[1])
		return (ft_error(-4, NAN));
	ret = 1;
	row = 0;
	ft_get_max_cols(s, fd);
	close(fd);
	fd = open(path, O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ft_check_line(s, line, ++row) == -1)
			ret = -1;
		free(line);
	}
	close(fd);
	if (ret == -1)
		return (FAILED);
	if (ft_create_spr_list(s) == -1 || ft_check_all(s) == -1)
		return (FAILED);
	return (SUCCESS);
}
