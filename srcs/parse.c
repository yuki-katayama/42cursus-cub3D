/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:08:32 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/24 11:21:03 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_invert_pixel(t_pixel *tex)
{
	int			i;
	int			j;
	uint32_t	tmp;

	i = -1;
	while (++i < tex->width / 2)
	{
		j = -1;
		while (++j < tex->height)
		{
			tmp = tex->buf[j * tex->width + i];
			tex->buf[j * tex->width + i] = \
				tex->buf[j * tex->width + (tex->width - i - 1)];
			tex->buf[j * tex->width + (tex->width - i - 1)] = tmp;
		}
	}
}

static void	ft_get_map_rows(char *path, t_sys *s)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	fd = open(path, O_RDONLY);
	line = NULL;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			break ;
		s->map.max_rows++;
		free(line);
	}
	close(fd);
	if (ret == -1)
	{
		ft_error(-37, -1);
		ft_close(s);
	}
}

static void	ft_gnl_free(int fd, char **line)
{
	while (get_next_line(fd, line))
		free(*line);
	free(*line);
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
		if (ft_check_line(s, line, ++row) == -1)
			ret = -1;
		free(line);
	}
	s->map.rows++;
	ft_gnl_free(fd, &line);
	close(fd);
	return (ret);
}

int	ft_parse(t_sys *s, char *path)
{
	int		fd;
	int		ret;

	ft_get_map_rows(path, s);
	ft_create_mlx(s);
	fd = open(path, O_RDONLY);
	if (fd == -1 || ft_strchr(path, '/') == NULL || !ft_strchr(path, '/')[1])
		return (ft_error(-4, -1));
	if (ft_strcmp(path + ft_strlen(path) - 4, ".cub"))
		return (ft_error(-38, -1));
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
	ft_invert_pixel(&s->tex.n);
	ft_invert_pixel(&s->tex.e);
	return (SUCCESS);
}
