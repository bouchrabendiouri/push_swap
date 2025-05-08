/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acses_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:29:08 by nolahmar          #+#    #+#             */
/*   Updated: 2023/05/10 14:20:17 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_acses(t_list *stack_a)
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
