/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:08:32 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/01 03:45:03 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_line_parse(t_sys *s, int fd)
{
	int		ret;
	int		row;
	int		err;
	char	*line;

	ret = 1;
	row = 0;
	err = 0;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (err == 0)
			if (ft_check_line(s, line, ++row) == -1)
				err = -1;
		free(line);
	}
	return (err);
}

int				ft_parse(t_sys *s, char *path)
{
	int		fd;
	int		err;

	err = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1 || ft_strchr(path, '/') == NULL || !ft_strchr(path, '/')[1])
		return (ft_error(-4, -1));
	err = ft_line_parse(s, fd);
	close(fd);
	if (err == -1)
		return (FAILED);
	if (ft_create_spr_list(s) == -1 || ft_check_all(s) == -1)
		return (FAILED);
	s->map.cols = s->map.max_cols;
	return (SUCCESS);
}
