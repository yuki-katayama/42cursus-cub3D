/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 01:24:39 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/08 13:30:01 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *i)
{
	unsigned long long	output;
	int					negative;
	int					keta;

	keta = -1;
	output = 0;
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
		if (++keta < 7)
			output = output * 10 + str[*i] - 48;
		(*i)++;
		if (output > 9223372036854775807 && negative == -1)
			return (0);
		if (output > 9223372036854775806 && negative == 1)
			return (-1);
	}
	return ((int)output * negative);
}
