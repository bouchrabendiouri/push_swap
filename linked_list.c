

#include "push_swap.h"

void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
	new->next = NULL;
}

t_list	*lstnew(int content)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}

void	lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		*lst = new;
	new->next = (*lst);
	(*lst) = new;
}

int	lstsize(t_list **lst)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
