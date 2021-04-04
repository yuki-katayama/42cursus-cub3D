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

.PHONY:	all
all:		$(NAME)

.PHONY:	san
san: 		$(OBJS)
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) ${OBJS} -g -fsanitize=address libft.a -L $(MLX) $(LXFLAGS) $(CFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

.PHONY:	clean
clean:
			@echo "\033[0;33mCleaning..."
			$(RM) $(OBJS)
			$(RM) $(BOBJS)
			$(RM) bitmap.bmp
			$(MAKE) clean -C ./mlx
			$(MAKE) clean -C ./libft
			@echo "\033[0m"

.PHONY:	fclean
fclean:		clean
			@echo "\033[0;33mRemoving executable..."
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME) ./libft.a
			@echo "\033[0m"

.PHONY:	bonus
bonus:		fclean $(BOBJS)
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./mlx
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) ${BOBJS} libft.a -L $(MLX) $(LXFLAGS) $(CFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

.PHONY:	re
re:			fclean all

.PHONY: test1
test1:
			./$(NAME) maps/map01.cub

.PHONY:	test2
test2:
			./$(NAME) maps/map02.cub

.PHONY:	test3
test3:
			./$(NAME) maps/map03.cub

.PHONY:	error
error:
			./$(NAME) maps/error.cub

.PHONY:	vast
vast:
			./$(NAME) maps/vast.cub

.PHONY:	big
big:
			./$(NAME) maps/big.cub

.PHONY:	small
small:
			./$(NAME) maps/small.cub

.PHONY:	bmp
bmp:
			./$(NAME) maps/map01.cub --save