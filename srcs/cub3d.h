/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 03:08:30 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/08 15:42:04 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <float.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>

# include "gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define TILE_SIZE 64

# define PI 3.14149265
# define TWO_PI 6.28318530

# define FAILED	-1
# define SUCCESS 0
# define EXIT 0
# define TRUE 1
# define FALSE 0

# define MINIMAP_SCALE_FACTOR 0.1

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define LIGHT_BLUE 0x00FFFF
# define MAGENTA 0xFF00FF

# define HORZ_INTENSITY 1
# define VERT_INTENSITY 1

# define WALK_SPEED 5
# define TURN_SPEED 5

# define PLAYER_HEIGHT 10
# define PLAYER_WIDTH 10

# define MAP_WIDTH 200
# define MAP_HEIGHT 200

# define FOV 60

# define EPSILON 0.3

typedef struct s_player {
	float	x;
	float	y;
	float	w;
	float	h;
	int		turn_dir;
	int		walk_dir;
	float	rot_a;
	float	walk_speed;
	float	turn_speed;
	float	a;
	int		num_player;
	char	side_dir;
	char	start_dir;
}				t_player;

typedef struct s_ray {
	float	ray_a;
	float	hit_x;
	float	hit_y;
	float	distance;
	char	texture;
	uint8_t	was_hit_vertical;
	uint8_t	was_hit_north;
	uint8_t	was_hit_east;
}				t_ray;

typedef struct s_pixel
{
	void		*ptr;
	uint32_t	*buf;
}				t_pixel;

typedef struct s_texture
{
	t_pixel	n;
	t_pixel	s;
	t_pixel	e;
	t_pixel	w;
	t_pixel	i;
	int		f;
	int		c;
	int		width;
	int		height;
}				t_texture;

typedef struct s_mlx
{
	void	*ptr;
}				t_mlx;

typedef struct s_win
{
	void	*ptr;
	uint8_t	exist;
	int		w;
	int		h;
}				t_win;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		max_cols;
	int		max_rows;
	int		num_spr;
	char	table[MAP_HEIGHT][MAP_WIDTH + 1];
}				t_map;

typedef struct s_sprite
{
	float	x;
	float	y;
	float	distance;
	float	a;
	uint8_t	visible;
	char	*file;
}				t_sprite;

typedef struct s_line
{
	float		x;
	float		y;
	float		w;
	float		h;
	uint32_t	color;
}				t_line;

typedef struct s_hit
{
	uint8_t	up;
	uint8_t	down;
	uint8_t	left;
	uint8_t	right;
}				t_hit;

typedef struct s_ray_tool
{
	float	xitcept;
	float	yitcept;
	float	next_x;
	float	next_y;
	float	xstep;
	float	ystep;
	uint8_t	found_wall_hit;
}				t_ray_tool;

typedef struct s_sprite_tool
{
	float		perp_distance;
	float		h;
	float		w;
	float		top_y;
	float		bottom_y;
	float		angle;
	float		screen_pos_x;
	float		left_x;
	float		right_x;
	float		texel_w;
	int			tex_w;
	int			tex_h;
	int			tex_ofs_x;
	int			tex_ofs_y;
	int			distance_from_top;
	uint32_t	*buff;
	uint32_t	c;
}				t_sprite_tool;

typedef struct s_wall_tool
{
	float		perp_distance;
	float		wall_h;
	int			wall_top_y;
	int			wall_bottom_y;
	int			tex_w;
	int			tex_h;
	int			fr_top;
	int			tex_ofs_x;
	int			tex_ofs_y;
	uint32_t	texel_color;
}				t_wall_tool;

typedef struct s_system
{
	t_mlx		mlx;
	t_win		win;
	t_pixel		pixels;
	t_texture	tex;
	t_ray		*rays;
	t_ray		vert;
	t_ray		horz;
	t_player	player;
	t_map		map;
	t_sprite	*spr;
	t_line		line;
	t_hit		hit;
	int			num_rays;
	int			err;
	uint8_t		bmp;
	float		dist_plane;
}				t_sys;

int					ft_init(t_sys *s, char *path);

int					ft_error(int e, int i);

void				ft_clear_color_buffer(uint32_t color, t_sys *s);
void				ft_draw_pixel(int x, int y, uint32_t color, t_sys *s);
void				ft_render_color_buffer(t_sys *s);

void				ft_create_window(t_sys *s);
void				ft_create_pixels(t_sys *s);
void				ft_create_texture(t_sys *s, t_pixel *adr, char *file);
void				ft_create_mlx(t_sys *s);

int					ft_press_key(int keycode, t_sys *s);
int					ft_release_key(int keycode, t_sys *s);

char				ft_map_has_wall_at(float x, float y, t_sys *s);
uint8_t				ft_is_inside_map(float x, float y, t_sys *s);
char				ft_get_map_at(int i, int j, t_sys *s);

int					ft_check_all(t_sys *s);
int					ft_check_line(t_sys *s, char *line, int row);

int					ft_parse(t_sys *s, char *path);

int					ft_set_colors(int *color, char *line, int *i);

int					ft_set_map(t_sys *s, char *line, int *i);

int					ft_set_player(t_sys *s, int x, int y, char c);

int					ft_set_tex(t_sys *s, t_pixel *adr, char *line, int *i);

int					ft_set_win(t_sys *s, char *line, int *i);

void				ft_move_player(t_sys *s);

void				ft_ray_vertical(float ray_a, t_sys *s);
void				ft_ray_horizontal(float ray_a, t_sys *s);

void				ft_cast_all_rays(t_sys *s);

void				ft_render_sprite_projection(t_sys *s);
int					ft_create_spr_list(t_sys *s);

void				ft_normalize_angle(float *angle);
float				ft_distance(float x1, float y1, float x2, float y2);

void				ft_render_wall_projection(t_sys *s);

int					ft_bitmap(t_sys *s);

int					ft_close(t_sys *s);

int					ft_check_map(t_sys *s);

#endif
