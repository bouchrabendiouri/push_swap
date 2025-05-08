

#include "push_swap.h"

void	init_index(t_list *stack_a)
{
	int	index;

	index = 0;
	while (stack_a)
	{
		stack_a->index = index;
		stack_a = stack_a->next;
		index++;
	}
}

int	get_min_element(t_list *stack_a)
{
	int	_min;
	int	index;

	_min = stack_a->content;
	index = stack_a->index;
	while (stack_a)
	{
		if (stack_a->content < _min)
		{
			_min = stack_a->content;
			index = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	return (index);
}

int	get_index_in_a(t_list *stack_a, int element)
{
	t_list	*greater_number;

	greater_number = get_greater_number(stack_a, element);
	if (greater_number)
		return (greater_number->index);
	return (get_min_element(stack_a));
}

t_list	*get_greater_number(t_list *stack_a, int element)
{
	t_list	*greater_number;
	t_list	*tmp;

	tmp = stack_a;
	greater_number = NULL;
	while (tmp)
	{
		if (tmp->content > element)
		{
			greater_number = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	while (stack_a)
	{
		if (stack_a->content > element
			&& stack_a->content < greater_number->content)
			greater_number = stack_a;
		stack_a = stack_a->next;
	}
	return (greater_number);
}

void	min_to_top(t_list **stack_a)
{
	t_list	*tmp;
	int		_min;

	tmp = *stack_a;
	_min = get_min_element(*stack_a);
	while ((*stack_a)->index != _min)
	{
		if (_min > lstsize(stack_a) / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
}
