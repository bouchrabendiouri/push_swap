

#include "push_swap.h"

int	ft_atoi(char *str, t_list *p)
{
	int		x;
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	x = 1;
	if (str[i] == '-')
	{
		x = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	if (ft_strlen(str) > 11 || nbr > INT_MAX || nbr < INT_MIN)
		ft_error_lst(p, 1);
	return (nbr * x);
}
