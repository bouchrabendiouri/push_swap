/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:22:00 by bbendiou          #+#    #+#             */
/*   Updated: 2023/05/10 17:22:12 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
