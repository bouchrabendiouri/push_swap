/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:31:26 by nolahmar          #+#    #+#             */
/*   Updated: 2023/05/10 14:44:44 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	a_is_sorted(t_list *nums)
{	
	while (nums)
	{
		if (nums->next)
		{
			if (nums->content > nums->next->content)
				return (1);
		}
		nums = nums->next;
	}
	return (0);
}
