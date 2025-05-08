

#include "push_swap.h"

void	ft_error_lst(t_list *p, int k)
{
	t_list	*s;

	if (k == 1)
		write (2, "Error\n", 6);
	else
		write (2, "Error\n", 6);
	if (!p)
		exit (5);
	while (p)
	{
		s = p;
		p = p->next;
		free(s);
	}
	exit (1);
}
