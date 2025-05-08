

#include "push_swap.h"

int	sort_three(t_list **a)
{
	int	t;
	int	m;
	int	b;
	int	i;

	t = (*a)->content;
	m = (*a)->next->content;
	b = (*a)->next->next->content;
	i = 0;
	if (t > m && m < b && b > t)
		i += sort_three_sa_and_write(a);
	if (t > m && m > b && b < t)
		i += sort_three_sa_rra(a);
	if (t > m && m < b && b < t)
		i += sort_three_ra_and_write(a);
	if (t < m && m > b && b > t)
		i += sort_three_sa_ra(a);
	if (t < m && m > b && b < t)
		i += sort_three_rra_and_write(a);
	if (a_is_sorted(*a) == 0)
		return (i);
	return (0);
}
