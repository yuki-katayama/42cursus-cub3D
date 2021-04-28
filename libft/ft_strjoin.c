/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:10:17 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/24 16:57:20 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	size_t	i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1);
	length += ft_strlen(s2);
	if (!(ft_malloc_p((void **)&dest, sizeof(char) * length + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < length)
	{
		dest[i] = *s2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
