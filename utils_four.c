

#include "push_swap.h"

int	min_cost(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return (min);
}

void	which_inst_to_do(t_list *stack_b, t_comb comb)
{
	if (stack_b->total_cost == comb.one)
	{
		stack_b->do_rra = 0;
		stack_b->do_rrb = 0;
	}
	else if (stack_b->total_cost == comb.two)
	{
		stack_b->do_rra = 1;
		stack_b->do_rrb = 0;
	}
	else if (stack_b->total_cost == comb.three)
	{
		stack_b->do_rra = 0;
		stack_b->do_rrb = 1;
	}
	else if (stack_b->total_cost == comb.four)
	{
		stack_b->do_rra = 1;
		stack_b->do_rrb = 1;
	}
}

void	total_cost(t_list *stack_b)
{
	t_comb	comb;

	while (stack_b)
	{
		comb.one = max(stack_b->cost_rb, stack_b->cost_ra);
		comb.two = stack_b->cost_rb + stack_b->cost_rra;
		comb.three = stack_b->cost_rrb + stack_b->cost_ra;
		comb.four = max(stack_b->cost_rrb, stack_b->cost_rra);
		stack_b->total_cost = min_cost(comb.one, comb.two,
				comb.three, comb.four);
		which_inst_to_do(stack_b, comb);
		stack_b = stack_b->next;
	}
}

t_list	*get_min_cost_element(t_list *stack_b)
{
	t_list	*ans;
	int		min;

	min = stack_b->total_cost;
	ans = stack_b;
	while (stack_b)
	{
		if (stack_b->total_cost < min)
		{
			min = stack_b->total_cost;
			ans = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (ans);
}
