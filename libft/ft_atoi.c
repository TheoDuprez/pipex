/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:41:56 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/01 14:49:38 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Atoi transform a string in int, in the limit of a long int */

static int	ft_check(int sign)
{
	if (sign == 1)
	{
		sign = -1;
		return (sign);
	}
	else
	{
		sign = 0;
		return (sign);
	}
}

long int	ft_atoi(const char *str)
{
	int			i;
	long int	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res != (res * 10) / 10)
			return (ft_check(sign));
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
