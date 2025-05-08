

#include "push_swap.h"

void	cost_ra(t_list *stack_a, t_list *stack_b)
{
	while (stack_b)
	{
		stack_b->cost_ra = get_index_in_a(stack_a, stack_b->content);
		stack_b = stack_b->next;
	}
}

void	cost_rra(t_list *stack_a, t_list *stack_b)
{
	t_list	*tail;

	tail = stack_a;
	while (tail->next)
		tail = tail->next;
	while (stack_b)
	{
		stack_b->cost_rra = tail->index
			- get_index_in_a(stack_a, stack_b->content) + 1;
		stack_b = stack_b->next;
	}
}

void	cost_rb(t_list *stack_b)
{
	while (stack_b)
	{
		stack_b->cost_rb = stack_b->index;
		stack_b = stack_b->next;
	}
}

void	cost_rrb(t_list *stack_b)
{
	t_list	*tail;

	tail = stack_b;
	while (tail->next)
		tail = tail->next;
	while (stack_b)
	{
		stack_b->cost_rrb = tail->index - stack_b->index + 1;
		stack_b = stack_b->next;
	}
}

void	reset_values(t_list *stack_b)
{
	while (stack_b)
	{
		stack_b->cost_rb = 0;
		stack_b->cost_rrb = 0;
		stack_b->cost_ra = 0;
		stack_b->cost_rra = 0;
		stack_b->total_cost = 0;
		stack_b->do_rra = 0;
		stack_b->do_rrb = 0;
		stack_b = stack_b->next;
	}
}
