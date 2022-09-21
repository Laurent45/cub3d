/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:05:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/01/11 16:47:06 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
 * Create a new node with content.
 * Return pointeur of new node or NULL if allocating failed
 */
t_list	*ft_lstnew(void *content);

/*
 * Add a new node at front of the list (new becoming first node).
 * Return: nothing
 */
void	ft_lstadd_front(t_list **alst, t_list *new);

/*
 * Get the size of the list.
 * Return: size of the list.
 */
int		ft_lstsize(t_list *lst);

/*
 * Return: the last node of the list
 */
t_list	*ft_lstlast(t_list *lst);

/*
 * Add a new node at back of the list (new becoming last node).
 * Return: nothing.
 */
void	ft_lstadd_back(t_list **alst, t_list *new);

/*
 * Delete the node lst with del.
 * Return: nothing.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/*
 * Delete all nodes with del.
 * Return: nothing.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/*
 * Loop each nodes and set content with f.
 * Return: nothing
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*
 * Loop each nodes and create a new list with the result set of f of node.
 * Del is necessary if a allocating failed.
 * Return: the new list (the first node)
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
