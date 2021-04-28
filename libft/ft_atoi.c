#include "libft.h"
#include <stdio.h>

static int	ft_pre_process(const char *str, int *i, int *negative)
{
	ft_spaceskip(str, i);
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*negative = *negative * -1;
		(*i)++;
	}
	if (str[*i] == '0' && str[*i + 1] >='0' && str[*i] <= '9')
		return (-1);
	return (0);
}

int	ft_atoi(const char *str, int *i)
{
	unsigned long long	output;
	int					negative;
	int					keta;

	keta = -1;
	output = 0;
	negative = 1;
	if (ft_pre_process(str, i, &negative) == -1)
		return (-1);
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
