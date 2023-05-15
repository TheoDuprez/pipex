/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:43:20 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/07 13:57:21 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_str_arr(int nb, ...)
{
	int		j;
	int		i;
	char	**tab;
	va_list	args;

	j = 0;
	va_start(args, nb);
	while (j < nb)
	{
		i = 0;
		tab = va_arg(args, char **);
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		j++;
	}
	va_end(args);
}
