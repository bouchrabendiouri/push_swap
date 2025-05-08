/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:24:39 by nolahmar          #+#    #+#             */
/*   Updated: 2023/05/05 15:54:31 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
	new->next = NULL;
}

t_list	*lstnew(int content)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}

void	lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		*lst = new;
	new->next = (*lst);
	(*lst) = new;
}

int	lstsize(t_list **lst)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

t_list	*lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
