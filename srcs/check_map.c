#include "cub3d.h"

static int	ft_check_surd_wall(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '0')
		return (TRUE);
	if (x + 1 >= MAP_WIDTH || y + 1 >= MAP_HEIGHT \
			|| x - 1 <= -1 || y - 1 <= -1)
		return (FALSE);
	map[y][x] = '0';
	if (map[y][x + 1] == '#')
		return (FALSE);
	if (map[y][x - 1] == '#')
		return (FALSE);
	if (map[y + 1][x] == '#')
		return (FALSE);
	if (map[y - 1][x] == '#')
		return (FALSE);
	return (ft_check_surd_wall(map, x, y + 1) \
			&& ft_check_surd_wall(map, x, y - 1) \
			&& ft_check_surd_wall(map, x + 1, y) \
			&& ft_check_surd_wall(map, x - 1, y));
}

static void	ft_free_tmp(char **tmp, int j)
{
	int	i;

	i = -1;
	while (++i < j)
		free(tmp[i]);
	free(tmp);
}

static void	ft_copy_tmp_to_map(char **tmp, t_sys *s)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	if (s->map.num_spr > 0)
	{
		while ((int)s->spr[++i].x > 0 && (int)s->spr[i].y > 0)
		{
			x = floor((s->spr[i].x) / TILE_SIZE);
			y = floor((s->spr[i].y) / TILE_SIZE);
			tmp[y][x] = '2';
		}
	}
	x = floor((s->player.x) / TILE_SIZE);
	y = floor((s->player.y) / TILE_SIZE);
	tmp[y][x] = s->player.start_dir;
	x = -1;
	y = -1;
	while (++x < MAP_WIDTH)
	{
		y = -1;
		while (++y < MAP_HEIGHT)
			s->map.table[y][x] = tmp[y][x];
	}
}

int	ft_check_map(t_sys *s)
{
	int		i;
	char	**tmp;

	if (!(ft_malloc_p((void **)&tmp, sizeof(char *) * (MAP_HEIGHT) + 1)))
		return (FAILED - 1);
	i = -1;
	while (++i < MAP_HEIGHT)
	{
		if (!(ft_malloc_p((void **)&tmp[i], sizeof(char) * (MAP_WIDTH) + 1)))
		{
			ft_free_tmp(tmp, i + 1);
			return (FAILED - 1);
		}
		ft_memcpy(tmp[i], s->map.table[i], MAP_WIDTH);
	}
	if (ft_check_surd_wall(tmp, s->player.x / TILE_SIZE, \
								s->player.y / TILE_SIZE) == 0)
		s->err = FAILED;
	if (s->err == 0)
		ft_copy_tmp_to_map(tmp, s);
	ft_free_tmp(tmp, MAP_HEIGHT);
	if (s->err == FAILED)
		return (s->err);
	return (SUCCESS);
}
