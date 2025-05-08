
#include "push_swap.h"

void	sa(t_list **lst, int k)
{
	int		swap;
	t_list	*a;

	if (!(*lst) || !(*lst)->next)
		return ;
	a = *lst;
	swap = a->content;
	a->content = a->next->content;
	a->next->content = swap;
	if (k)
		write (1, "sa\n", 3);
}

void	sb(t_list **lst, int k)
{
	int	swap;

	if (!(*lst) || !(*lst)->next)
		return ;
	swap = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = swap;
	if (k)
		write (1, "sb\n", 3);
}

void	ra(t_list **lst, int k)
{
	t_list	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL;
	lstadd_back(lst, p);
	if (k)
		write (1, "ra\n", 3);
}

void	rb(t_list **lst, int k)
{
	t_list	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL;
	lstadd_back(lst, p);
	if (k)
		write (1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int k)
{
	ra(a, 0);
	rb(b, 0);
	if (k)
		write (1, "rr\n", 3);
}
