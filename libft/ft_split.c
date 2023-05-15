/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:12:04 by tduprez           #+#    #+#             */
/*   Updated: 2023/02/27 14:57:04 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_nbword(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*ft_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (ft_len(s, c) + 1));
	if (!word)
		return (NULL);
	while (i < ft_len(s, c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_splitter(char const *s, char **str, char c, int i)
{
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != 0)
		{
			str[i] = ft_word(s, c);
			if (str[i] == NULL)
			{
				while (i + 1 > 0)
				{
					free(str[i]);
					i--;
				}
				free(str);
				return (NULL);
			}
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	str = malloc(sizeof(char *) * (ft_nbword(s, c) + 1));
	if (!str || !s)
		return (NULL);
	return (ft_splitter(s, str, c, i));
}
