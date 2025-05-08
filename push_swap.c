

#include "push_swap.h"

int	acses(t_list *stack_a)
{
	int	min;

	if (stack_a)
	{
		min = stack_a->content;
		stack_a = stack_a->next;
	}
	while (stack_a)
	{
		if (min > stack_a->content)
			return (-1);
		min = stack_a->content;
		stack_a = stack_a->next;
	}
	return (0);
}

void	push_swap(t_list **stack_a)
{
	t_list	*b;

	b = 0;
	if (lstsize(stack_a) == 1 || acses(*stack_a) == 0)
		exit (0);
	else if (lstsize(stack_a) == 2)
		sa(stack_a, 1);
	else if (lstsize(stack_a) == 3)
		sort_three(stack_a);
	else if (lstsize(stack_a) == 5 || lstsize(stack_a) == 4)
		sort_five(stack_a, &b);
	else
		sort(&(*stack_a), &b);
}
