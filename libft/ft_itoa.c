/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:32:08 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/23 14:14:33 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Itoa convert a int into string */

static int	ft_len_int(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		i++;
	}
	if (n == 0)
		i++;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	nb;

	nb = n;
	i = ft_len_int(n);
	str = malloc(sizeof(char) * ft_len_int(n) + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[i] = 0;
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	i--;
	while (nb > 0)
	{
		str[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	return (str);
}
