/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 02:15:34 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/24 15:49:54 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_atoi(const char *str, int *i);
int		ft_spaceskip(const char *str, int *i);
int		ft_haschar(const char *s, int c);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_free(char **word, int index);
size_t	ft_strlen(const char *s);
float	ft_sqrt(float nb);
int		ft_strcmp(const char *s1, const char *s2);

#endif
