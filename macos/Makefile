NAME	=	cub3D

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

MLX		=	mlx

LXFLAGS	=	-lmlx -framework OpenGL -framework AppKit

SRCDIR	=	./srcs/

SRCNAME	=	main\
			wall\
			ray\
			ray_vert \
			ray_horz \
			player\
			sprite \
			map\
			graphics\
			key\
			error \
			close \
			utils \
			init \
			bitmap \
			create_tools \
			check \
			check_map \
			parse \
			parse_map \
			parse_color \
			parse_window \
			parse_texture \
			parse_player \
			gnl/get_next_line\

BSRCNAME =	render_map \
			draw

SRCS	=	$(addsuffix .c, $(addprefix srcs/, $(SRCNAME)))

BSRCS	=	$(addsuffix _bonus.c, $(addprefix bonus/, $(SRCNAME) $(BSRCNAME)))

OBJS	=	$(SRCS:.c=.o)

BOBJS	=	$(BSRCS:.c=.o)


$(NAME):	$(OBJS)
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./mlx
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) ${OBJS} ./libft/libft.a -L $(MLX) $(LXFLAGS) $(CFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

all:		$(NAME)

san: 		$(OBJS)
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) ${OBJS} -g -fsanitize=address libft.a -L $(MLX) $(LXFLAGS) $(CFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

clean:
			@echo "\033[0;33mCleaning..."
			$(RM) $(OBJS)
			$(RM) $(BOBJS)
			$(RM) bitmap.bmp
			$(MAKE) clean -C ./mlx
			$(MAKE) clean -C ./libft
			@echo "\033[0m"


fclean:		clean
			@echo "\033[0;33mRemoving executable..."
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME) ./libft.a
			@echo "\033[0m"

bonus:		fclean $(BOBJS)
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./mlx
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) ${BOBJS} libft.a -L $(MLX) $(LXFLAGS) $(CFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

re:			fclean all


test1:
			./$(NAME) maps/map01.cub

test2:
			./$(NAME) maps/map02.cub

test3:
			./$(NAME) maps/map03.cub

error:
			./$(NAME) maps/error.cub

vast:
			./$(NAME) maps/vast.cub

big:
			./$(NAME) maps/big.cub

small:
			./$(NAME) maps/small.cub

bmp:
			./$(NAME) maps/map01.cub --save

.PHONY: all clean fclean re bonus