/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:29:17 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/16 15:24:58 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;
	void	*content;
	int		size;

	content = NULL;
	new_lst = NULL;
	size = ft_lstsize(lst);
	while (size > 0)
	{
		tmp = lst->next;
		content = lst->content;
		ft_lstadd_back(&new_lst, ft_lstnew(f(content)));
		lst = tmp;
		size--;
	}
	if (!new_lst)
		ft_lstclear(&new_lst, del);
	return (new_lst);
}
