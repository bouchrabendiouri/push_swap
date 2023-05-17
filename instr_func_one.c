/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_func_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:23:46 by bbendiou          #+#    #+#             */
/*   Updated: 2023/05/10 17:24:08 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**sa(t_list **lst, int k)
{
	int		swap;
	t_list	*a;

	if (!(*lst) || !(*lst)->next)
		return (NULL);
	a = *lst;
	swap = a->content;
	a->content = a->next->content;
	a->next->content = swap;
	if (k)
		write (1, "sa\n", 3);
	return (lst);
}

void	sb(t_list **lst, int k)
{
	int	swap;

	if (!(*lst) || !(*lst)->next)
		return ;
	swap = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = swap;
	if (k)
		write (1, "sb\n", 3);
}

void	ra(t_list **lst, int k)
{
	t_list	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL;
	lstadd_back(lst, p);
	if (k)
		write (1, "ra\n", 3);
}

void	rb(t_list **lst, int k)
{
	t_list	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL;
	lstadd_back(lst, p);
	if (k)
		write (1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int k)
{
	t_list	*p;

	if (!(*a) || !(*a) || !(*a)->next || !(*b)->next)
		return ;
	p = (*a);
	(*a) = (*a)->next;
	p->next = NULL;
	lstadd_back(a, p);
	p = (*b);
	(*b) = (*b)->next;
	p->next = NULL;
	lstadd_back(b, p);
	if (k)
		write (1, "rr\n", 3);
}
