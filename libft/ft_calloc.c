/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:08:29 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/23 14:08:47 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Calloc create a void array of '\0', with (count * size) */

void	*ft_calloc(size_t count, size_t size)
{
	void			*tab;
	unsigned int	size_tab;
	size_t			i;

	i = 0;
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	size_tab = count * size;
	tab = malloc(size_tab);
	if (!tab)
		return (NULL);
	while (i < size_tab)
	{
		((char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}
