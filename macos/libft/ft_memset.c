/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:03:16 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:03:17 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*b1;

	b1 = b;
	i = 0;
	while (i++ < (int)len)
	{
		*(unsigned char *)b = (unsigned char)c;
		b++;
	}
	return (b1);
}
