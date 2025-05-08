
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
