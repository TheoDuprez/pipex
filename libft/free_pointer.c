/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:45:37 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/01 14:49:31 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_pointer(int nb, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, nb);
	while (i < nb)
	{
		free(va_arg(args, void *));
		i++;
	}
	va_end(args);
}
