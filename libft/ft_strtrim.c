/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:18:57 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/13 15:59:08 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len_start;
	int		len_end;
	char	*new_str;

	i = 0;
	len_start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[len_start] && ft_is_set(s1[len_start], set))
		len_start++;
	len_end = ft_strlen(s1);
	while (len_end > len_start && ft_is_set(s1[len_end - 1], set))
		len_end--;
	new_str = malloc(sizeof(char) * (len_end - len_start) + 1);
	if (!new_str)
		return (NULL);
	while (len_start < len_end)
	{
		new_str[i] = s1[len_start];
		i++;
		len_start++;
	}
	new_str[i] = 0;
	return (new_str);
}
