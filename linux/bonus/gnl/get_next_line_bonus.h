/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:58:04 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/01 02:28:29 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include "../../libft/libft.h"

# define READ 1
# define READ_EOF 0
# define READ_ERROR -1
# define BUFFER_SIZE 1024

int			get_next_line(const int fd, char **line);

#endif
