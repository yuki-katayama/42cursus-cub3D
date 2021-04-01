# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 17:12:33 by kyuki             #+#    #+#              #
#    Updated: 2021/03/28 23:02:00 by kyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libft.a

CC	= gcc

CFLAGS	= -Wall	-Wextra	-Werror

RM		=	rm -f

INCDIR	=	./libft

SRCDIR	=	./

SRCNAME	=	ft_split.c \
			ft_free.c \
			ft_atoi.c \
			ft_spaceskip.c \
			ft_haschar.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strchr.c \
			ft_substr.c \
			ft_isdigit.c \
			ft_sqrt.c \
			ft_strcmp.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c

SRCS	=	$(addprefix $(SRCDIR), $(SRCNAME))

OBJS	=	$(SRCS:.c=.o)

.c.o:
		$(CC) $(CFLAGS)	-I $(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar	rcs	$(NAME)	$(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
