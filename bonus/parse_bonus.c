/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:08:32 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/31 20:35:13 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int				ft_parse(t_sys *s, char *path)
{
	char	*line;
	int		fd;
	int		ret;
	int		row;

	fd = open(path, O_RDONLY);
	if (fd == -1 || ft_strchr(path, '/') == NULL || !ft_strchr(path, '/')[1])
		return (ft_error(-4, -1));
	ret = 1;
	row = 0;
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
	s->map.cols = s->map.max_cols;
	return (SUCCESS);
}
