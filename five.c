/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:29:12 by bbendiou          #+#    #+#             */
/*   Updated: 2023/05/10 17:29:25 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_min(t_list *stack_a, int min)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->content == min)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

int	min_five(t_list *stack_a, int *min)
{
	t_list	*a;
	int		index;

	a = stack_a;
	*min = a->content;
	a = a->next;
	while (a)
	{
		if (*min > a->content)
			*min = a->content;
		a = a->next;
	}
	index = index_min(stack_a, *min);
	return (index);
}

void	sort_five(t_list **stack_a, t_list **b)
{
	int	index;
	int	min;

	while (lstsize(stack_a) > 3)
	{
		index = min_five(*stack_a, &min);
		if (index >= (5 / 2))
		{
			while ((*stack_a)->content != min)
				rra(stack_a, 1);
			pb(b, stack_a, 1);
		}
		else if (index < (5 / 2))
		{
			while ((*stack_a)->content != min)
				ra(stack_a, 1);
			pb(b, stack_a, 1);
		}
	}
	sort_three(stack_a);
	while (*b)
		pa(stack_a, b, 1);
}
