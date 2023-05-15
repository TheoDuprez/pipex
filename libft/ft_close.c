/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:48:39 by tduprez           #+#    #+#             */
/*   Updated: 2023/02/28 15:48:45 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_close(int nb, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, nb);
	while (i < nb)
	{
		close(va_arg(args, int));
		i++;
	}
	va_end(args);
}
