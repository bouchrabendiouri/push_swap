/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:25:19 by nolahmar          #+#    #+#             */
/*   Updated: 2023/05/23 14:42:46 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	help(char *s, t_list **stack_a, t_list **stack_b)
{
	if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		pa(stack_a, stack_b, 0);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		pb(stack_b, stack_a, 0);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		ra(stack_a, 0);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		rb(stack_b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		rr(stack_a, stack_b, 0);
	else if (s[2] == '\n')
		error_exit();
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		rra(stack_a, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		rrb(stack_b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		rrr(stack_a, stack_b, 0);
	else
		error_exit();
}

void	check_ok_ko(t_list **stack_a, t_list *stack_b)
{
	if (ft_acses(*stack_a) == 0 && (!stack_b))
		write (2, "OK\n", 3);
	else
	{
		if (stack_b)
		{
			while (stack_b)
			{
				free(stack_b);
				stack_b = stack_b->next;
			}
		}
		write (2, "KO\n", 3);
	}
}

void	checker(t_list **stack_a)
{
	t_list	*stack_b;
	char	*str;

	stack_b = NULL;
	str = "";
	while (str)
	{
		str = get_next_line(0);
		if (!str || !str[0])
			break ;
		if (str[0] == '\n' || str[1] == '\n')
			error_exit();
		if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
			sa(stack_a, 0);
		else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
			sb(&stack_b, 0);
		else
			help(str, stack_a, &stack_b);
		free(str);
	}
	check_ok_ko(stack_a, stack_b);
}
