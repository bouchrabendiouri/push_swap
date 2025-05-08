

#include "push_swap.h"

void	init_and_calc_cost(t_list *stack_a, t_list *stack_b)
{
	init_index(stack_a);
	init_index(stack_b);
	reset_values(stack_b);
	cost_rb(stack_b);
	cost_rrb(stack_b);
	cost_ra(stack_a, stack_b);
	cost_rra(stack_a, stack_b);
	total_cost(stack_b);
}

int	do_rr(t_list **stack_a, t_list **stack_b, t_list *curr_element)
{
	int	_min;
	int	diff;

	if (!curr_element->do_rra && !curr_element->do_rrb
		&& curr_element->cost_ra && curr_element->cost_rb)
	{
		_min = min(curr_element->cost_ra, curr_element->cost_rb);
		diff = max(curr_element->cost_ra, curr_element->cost_rb) - _min;
		while (_min--)
			rr(stack_a, stack_b, 1);
		if (max(curr_element->cost_ra, curr_element->cost_rb)
			== curr_element->cost_ra)
			while (diff--)
				ra(stack_a, 1);
		else
			while (diff--)
				rb(stack_b, 1);
		pa(stack_a, stack_b, 1);
		return (1);
	}
	return (0);
}

int	do_rrr(t_list **stack_a, t_list **stack_b, t_list *curr_element)
{
	int	_min;
	int	diff;

	if (curr_element->do_rra && curr_element->do_rrb
		&& curr_element->cost_rra && curr_element->cost_rrb)
	{
		_min = min(curr_element->cost_rra, curr_element->cost_rrb);
		diff = max(curr_element->cost_rra, curr_element->cost_rrb) - _min;
		while (_min--)
			rrr(stack_a, stack_b, 1);
		if (max(curr_element->cost_rra, curr_element->cost_rrb)
			== curr_element->cost_rra)
			while (diff--)
				rra(stack_a, 1);
		else
			while (diff--)
				rrb(stack_b, 1);
		pa(stack_a, stack_b, 1);
		return (1);
	}
	return (0);
}

void	do_other_inst(t_list **stack_a, t_list **stack_b, t_list *curr_element)
{
	if (curr_element->do_rrb)
		while (curr_element->cost_rrb--)
			rrb(stack_b, 1);
	else
		while (curr_element->cost_rb--)
			rb(stack_b, 1);
	if (curr_element->do_rra)
	{
		while (curr_element->cost_rra--)
			rra(stack_a, 1);
		pa(stack_a, stack_b, 1);
	}
	else
	{
		while (curr_element->cost_ra--)
			ra(stack_a, 1);
		pa(stack_a, stack_b, 1);
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr_element;

	while (lstsize(stack_a) > 1)
		pb(stack_b, stack_a, 1);
	while (lstsize(stack_b))
	{
		init_and_calc_cost(*stack_a, *stack_b);
		curr_element = get_min_cost_element(*stack_b);
		if (do_rrr(stack_a, stack_b, curr_element))
			continue ;
		if (do_rr(stack_a, stack_b, curr_element))
			continue ;
		do_other_inst(stack_a, stack_b, curr_element);
	}
	init_index(*stack_a);
	min_to_top(stack_a);
}
