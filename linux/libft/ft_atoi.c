/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 01:24:39 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/11 15:36:07 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *i)
{
	unsigned long long	atoi;
	int					negative;

	atoi = 0;
	negative = 1;
	ft_spaceskip(str, i);
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			negative = negative * -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		atoi = atoi * 10 + str[*i] - 48;
		(*i)++;
		if (atoi > 9223372036854775807 && negative == -1)
			return (0);
		if (atoi > 9223372036854775806 && negative == 1)
			return (-1);
	}
	return ((int)atoi * negative);
}
