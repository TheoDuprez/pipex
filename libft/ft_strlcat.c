/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:09:37 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/13 20:06:52 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	while (dst[len] && len < dstsize)
		len++;
	while (src[i] && dstsize && len + i < dstsize - 1)
	{
		dst[len + i] = src[i];
		i++;
	}
	if (len < dstsize)
		dst[len + i] = 0;
	i = 0;
	while (src[i])
		i++;
	return (len + i);
}
