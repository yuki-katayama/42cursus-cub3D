NAME	=	cub3D

CC		=	gcc

CFLAGS	=	-Wextra -Wall -Werror


MLX		= minilibx-linux

LXFLAGS	=	-lm -lXext -lX11

SRCDIR  = ./srcs/

SRCS    = $(addprefix $(SRCDIR), $(SRCNAME))

VALGRIND = valgrind

VALFLAGS = --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666

SRCNAME	=	main\
			wall\
			wall2\
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

.PHONY: all
all		:	$(NAME)

$(MLX)	:
    		git clone https://github.com/42Paris/minilibx-linux.git $(MLX)

$(NAME) :	$(MLX) ${OBJS}
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./libft
			$(MAKE) -C ./minilibx-linux
			cp ./minilibx-linux/libmlx_Linux.a .
			cp ./libft/libft.a .
			$(CC) ${OBJS} libmlx_Linux.a libft.a $(CFLAGS) $(LXFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

.PHONY: san
san		:	$(MLX) ${OBJS}
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./libft
			cp ./minilibx-linux/libmlx_Linux.a .
			cp ./libft/libft.a .

			$(CC) ${OBJS} -g -fsanitize=address libmlx_Linux.a libft.a $(CFLAGS) $(LXFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

.PHONY: val
val		:	$(MLX) ${OBJS}
			$(MAKE) -C ./libft
			cp ./minilibx-linux/libmlx_Linux.a .
			cp ./libft/libft.a .
			$(CC) -g ${OBJS} libmlx_Linux.a libft.a $(CFLAGS) $(LXFLAGS) -o ${NAME}
			$(VALGRIND) $(VALFLAGS) ./cub3D ./map01.cub --save

.PHONY: clean
clean	:	${MLX}
			@echo "\033[0;33mCleaning..."
			$(RM) $(OBJS) $(BOBJS)
			$(RM) bitmap.bmp
			$(MAKE) clean -C ./libft
			$(MAKE) clean -C ./${MLX}
			@echo "\033[0m"

.PHONY: fclean
fclean	:	clean
			@echo "\033[0;33mRemoving executable..."
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME) libft.a libmlx_Linux.a
			@echo "\033[0m"

.PHONY: re
re		:	fclean all

.PHONY: bonus
bonus:	fclean $(MLX) $(BOBJS)
		@echo "\n\033[0;32mCompiling..."
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx-linux
		cp ./minilibx-linux/libmlx_Linux.a .
		cp ./libft/libft.a .
		$(CC) ${BOBJS} libmlx_Linux.a libft.a $(CFLAGS) $(LXFLAGS) -o ${NAME}
		@echo "Complete\033[0m"

.PHONY: test1
test1	:
			./$(NAME) maps/map01.cub

.PHONY: test2
test2	:
			./$(NAME) maps/map02.cub

.PHONY: test3
test3	:
			./$(NAME) maps/map03.cub

.PHONY: error
error	:
			./$(NAME) maps/error.cub

.PHONY: vast
vast	:
			./$(NAME) maps/vast.cub

.PHONY: big
big		:
			./$(NAME) maps/big.cub

.PHONY: small
small	:
			./$(NAME) maps/small.cub

.PHONY: bmp
bmp		:
			./$(NAME) maps/map03.cub --save
