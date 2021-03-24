/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 04:36:56 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/18 19:59:02 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_sqrt(float x)
{
	int		i;
	float	y;
	float	z;
	float	result;

	if (x == 0)
		return (0);
	else
	{
		y = 1;
		i = -1;
		while (++i <= 10)
		{
			z = x / y;
			result = (y + z) / 2;
			y = result;
		}
	}
	return (result);
}
