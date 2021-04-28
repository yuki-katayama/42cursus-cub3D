#include "cub3d.h"

static int32_t	ft_set_color(char *line, int *i)
{
	int32_t	color;

	color = ft_atoi(line, i);
	if (ft_haschar(&line[*i], ',') == -1)
		return (-19);
	ft_spaceskip(line, i);
	(*i)++;
	return (color);
}

static void	ft_color_parse(int32_t *color, char *line, int *i, int *miss_param)
{
	ft_spaceskip(line, i);
	if (!('0' <= line[*i] && line[*i] <= '9'))
		*miss_param = 1;
	*color = ft_set_color(line, i);
}

int	ft_set_colors(int *color, char *line, int *i)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int		miss_param;

	miss_param = 0;
	if (*color != -1)
		return (-29);
	(*i)++;
	ft_color_parse(&r, line, i, &miss_param);
	ft_color_parse(&g, line, i, &miss_param);
	ft_spaceskip(line, i);
	if (!('0' <= line[*i] && line[*i] <= '9'))
		miss_param = 1;
	b = ft_atoi(line, i);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-19);
	else if (line[*i] != '\0')
		return (-19);
	else if (miss_param == 1)
		return (-19);
	*color = (uint32_t)(r * 256 * 256) + (g * 256) + (b);
	return (SUCCESS);
}
