/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:45:33 by lfrederi          #+#    #+#             */
/*   Updated: 2021/12/23 16:36:03 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_lst.h"
#include <stddef.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*tmp;
	t_list	*next;

	if (!lst)
		return (NULL);
	map = ft_lstnew(f(lst->content));
	if (!map)
		return (NULL);
	tmp = lst->next;
	while (tmp)
	{
		next = ft_lstnew(f(tmp->content));
		if (!next)
		{
			ft_lstclear(&map, del);
			break ;
		}
		ft_lstadd_back(&map, next);
		tmp = tmp->next;
	}
	return (map);
}
