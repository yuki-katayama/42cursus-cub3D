/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:00:56 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/04 11:31:51 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_error03(int e, int i)
{
	if (e == -27)
		printf("Failed to malloc sprite.\n");
	else if (e == -28)
		printf("Line %d: Declaring the sprite texture twice.\n", i);
	else if (e == -29)
		printf("Line %d: Declaring the color twice.\n", i);
	else if (e == -30)
		printf("Missing sprite texture.\n");
	else if (e == -31)
		printf("Missing floor color.\n");
	else if (e == -32)
		printf("Missing ceil color.\n");
	else if (e == -33)
		printf("Failed to malloc copy of map.\n");
	else if (e == -34)
		printf("Line %d: Set the width of the map to 3 <= w <= 200.\n", i);
	else if (e == -35)
		printf("Line %d: Set the height of the map to 3 <= h <= 200.\n", i);
	else if (e == -36)
		printf("Failed to malloc rays.\n");
	else if (e == -37)
		printf("Directory was specified.\n");
}

static void	ft_error02(int e, int i)
{
	if (e == -14)
		printf("Line %d: Declaring the direction texture twice.\n", i);
	else if (e == -15)
		printf("Line %d: No texture specified.\n", i);
	else if (e == -16)
		printf("Line %d: Texture has no extension.\n", i);
	else if (e == -17)
		printf("Line %d: Color parameters are too low or too high.\n", i);
	else if (e == -18)
		printf("Line %d: Missing parameter of color.\n", i);
	else if (e == -19)
		printf("Line %d: Invalid color parameter.\n", i);
	else if (e == -20)
		printf("Line %d: Failed to malloc texture.\n", i);
	else if (e == -22)
		printf("Line %d: Invalid value in map.\n", i);
	else if (e == -23)
		printf("Missing parameter of player.\n");
	else if (e == -24)
		printf("Line %d: Declaring the player twice.\n", i);
	else if (e == -25)
		printf("No Surrounded by wall.\n");
	else if (e == -26)
		printf("Missing parameter or too many paramater.\n");
}

static void	ft_error01(int e, int i)
{
	if (e == -2)
		printf("Line %d: Invalid resolution.\n", i);
	else if (e == -3)
		printf("Line %d: Invalid file in line.\n", i);
	else if (e == -4)
		printf("Couldn't open .cub file.\n");
	else if (e == -5)
		printf("Line %d: Declaring the resolution twice.\n", i);
	else if (e == -6)
		printf("Line %d: Invalid extenstion of texture file.\n", i);
	else if (e == -7)
		printf("Line %d: Cannot find the specified .xpm file.\n", i);
	else if (e == -8)
		printf("Line %d: Invalid texture size.\n", i);
	else if (e == -9)
		printf("Missing north texture.\n");
	else if (e == -10)
		printf("Missing south texture.\n");
	else if (e == -11)
		printf("Missing west texture.\n");
	else if (e == -12)
		printf("Missing east texture.\n");
	else if (e == -13)
		printf("No resolution specified.\n");
}

int			ft_error(int e, int i)
{
	printf("Error\n");
	if (e <= -2 && e >= -13)
		ft_error01(e, i);
	else if (e <= -14 && e >= -26)
		ft_error02(e, i);
	else if (e <= -27 && e >= -37)
		ft_error03(e, i);
	return (FAILED);
}
