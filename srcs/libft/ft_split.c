/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:09:46 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/09 15:50:11 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_if_sep(char c, char charset)
{
	int	i;

	i = 0;
	if (c == charset)
		return (1);
	return (0);
}

static int	count_str(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (check_if_sep(str[i], sep))
			i++;
		count++;
		while (str[i] && !(check_if_sep(str[i], sep)))
			i++;
	}
	return (count);
}

static int	ft_strlen_sep(char const *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] && (!check_if_sep(s[i], sep)))
		i++;
	return (i);
}

static char	*assign_res(char const *str, char sep)
{
	int		i;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen_sep(str, sep) + 1))))
		return (NULL);
	i = 0;
	while (str[i] && !(check_if_sep(str[i], sep)))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;
	int		j;

	if (!s)
		return (NULL);
	if (!(words = (char **)malloc(sizeof(char *) * (count_str(s, c) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (s[i] && s != NULL)
	{
		while (s[i] && check_if_sep(s[i], c))
			i++;
		if (s[i])
		{
			if (!(words[j++] = assign_res(s + i, c)))
				return (ft_free(words, (int)i));
		}
		while (s[i] && !(check_if_sep(s[i], c)))
			i++;
	}
	words[j] = NULL;
	return (words);
}
