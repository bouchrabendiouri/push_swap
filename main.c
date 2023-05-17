/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:20:18 by bbendiou          #+#    #+#             */
/*   Updated: 2023/05/10 17:20:45 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	check_dig_sign(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if ((av[i][j] == '-' && av[i][j + 1]) ||
				(av[i][j] == '+' && av[i][j + 1]))
			j++;
		while (av[i][j])
		{
			if ((av[i][j] == '+' && av[i][j - 1] == ' '
						&& av[i][j + 1] != ' ') ||
					(av[i][j] == '-' && av[i][j - 1] == ' ' &&
					av[i][j + 1] != ' '))
				j++;
			else if ((av[i][j] == ' ') || (av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

int	repeat_of_numbers(t_list *p)
{
	t_list	*s;

	if (!p)
		ft_error_lst(p, 0);
	s = p->next;
	while (p)
	{
		s = p->next;
		while (s)
		{
			if (p->content == s->content)
				return (1);
			s = s->next;
		}
		p = p->next;
	}
	return (0);
}

t_list	*concat_arg(char **av)
{
	int		i;
	int		j;
	char	**s;
	t_list	*p;

	i = 0;
	p = NULL;
	while (av[i])
	{
		s = ft_split(av[i], ' ');
		if (!s)
			ft_error_lst(p, 0);
		j = 0;
		while (s[j])
		{
			lstadd_back(&p, lstnew(ft_atoi(s[j], p)));
			free(s[j]);
			j++;
		}
		free(s);
		i++;
	}
	return (p);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (ac < 2)
		return (1);
	if (check_dig_sign(av) == -1)
	{
		write (2, "Error\n", 6);
		return (1);
	}
	stack_a = concat_arg(av + 1);
	if (repeat_of_numbers(stack_a) == 1)
		ft_error_lst(stack_a, 1);
	else if (lstsize(&stack_a) == 0)
		ft_error_lst(stack_a, 2);
	push_swap(&stack_a);
}
