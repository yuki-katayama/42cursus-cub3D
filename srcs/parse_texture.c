/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:02:34 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/27 00:09:39 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_extension(char *str, char *ext)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if ((i > 4 && str[i - 1] == ext[3] && str[i - 2] == ext[2]) \
		&& (str[i - 3] == ext[1] && str[i - 4] == ext[0]))
		return (SUCCESS);
	return (FAILED);
}

static int	ft_confirm_file(t_sys *s, t_pixel *adr, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (*file == '\0')
		return (-15);
	else if (file[0] != '.')
		return (-8);
	else if (ft_haschar(file, '.') == -1)
		return (-16);
	else if (ft_check_extension(file, ".xpm") == -1)
		return (-6);
	else if (fd == -1)
		return (-7);
	close(fd);
	ft_create_texture(s, adr, file);
	return (SUCCESS);
}

int	ft_tex_error(t_sys *s)
{
	if (s->tex.i.ptr != NULL)
		return (-28);
	return (-14);
}

int	ft_set_tex(t_sys *s, t_pixel *adr, char *line, int *i)
{
	char	*file;
	int		j;

	if (adr->ptr != NULL)
		return (ft_tex_error(s));
	(*i) += 2;
	ft_spaceskip(line, i);
	j = *i;
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(ft_malloc_p((void **)&file, (sizeof(char) * (*i - j)) + 1)))
		return (-20);
	*i = j;
	j = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		file[j++] = line[(*i)++];
	file[j] = '\0';
	s->err = ft_confirm_file(s, adr, file);
	free(file);
	if (s->err < 0)
		return (s->err);
	return (SUCCESS);
}
