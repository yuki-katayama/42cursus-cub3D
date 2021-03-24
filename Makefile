NAME    = cub3D
CC      = gcc
CFLAGS  =  -Wall -Werror -Wextra -lm -lXext -lX11
AR      = ar
ARFLAGS = scr
SRCDIR  = srcs/
MLX     = minilibx-linux
SRCNAME = main.c\
			wall.c\
			ray.c\
			ray_vert.c \
			ray_horz.c \
			player.c\
			sprite.c \
			map.c\
			graphics.c\
			key.c\
			error.c \
			utils.c \
			init.c \
			bitmap.c \
			render_map.c \
			create_tools.c \
			destroy_tools.c \
			check.c \
			parse.c \
			parse_map.c \
			parse_color.c \
			parse_window.c \
			parse_texture.c \
			parse_player.c \
			gnl/get_next_line.c\
			libft/ft_split.c \
			libft/ft_free.c \
			libft/ft_atoi.c \
			libft/ft_spaceskip.c \
			libft/ft_haschar.c \
			libft/ft_strlen.c \
			libft/ft_strdup.c \
			libft/ft_strjoin.c \
			libft/ft_strchr.c \
			libft/ft_substr.c \
			libft/ft_isdigit.c \
			libft/ft_sqrt.c \
			libft/ft_strcmp.c
SRCS    = $(addprefix $(SRCDIR), $(SRCNAME))
OBJS    = $(SRCS:.c=.o)

all     : $(NAME)

$(MLX) :
    git clone https://github.com/42Paris/minilibx-linux.git $(MLX)
$(NAME) : $(MLX) ${OBJS}
    $(MAKE) -C ./libft
    $(MAKE) -C ./minilibx-linux
    cp ./minilibx-linux/libmlx_Linux.a .
    cp .srcs/libft/libft.a .
    $(CC) ${OBJS} libmlx_Linux.a libft.a $(CFLAGS) -o ${NAME}

san        : $(MLX) ${OBJS}
    $(MAKE) -C .srcs/libft
    $(MAKE) -C ./minilibx-linux
    cp ./minilibx-linux/libmlx_Linux.a .
    cp ./srcs/libft/libft.a .
    $(CC) -g -fsanitize=address ${OBJS} libmlx_Linux.a libft.a $(CFLAGS) -o ${NAME}

clean   : ${MLX}
    $(MAKE) clean -C ./libft
    $(MAKE) clean -C ${MLX}
    $(RM) $(OBJS) $(B_OBJS)

fclean  : clean
    $(MAKE) fclean -C ./libft
    $(RM) $(NAME) libft.a libmlx_Linux.a *.bmp

re      : fclean all

.PHONY  : all clean fclean re bonus