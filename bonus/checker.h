/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:51:48 by nolahmar          #+#    #+#             */
/*   Updated: 2023/05/23 11:44:03 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

void	checker(t_list **stack_a);
int		ft_atoi(char *str, t_list *p);
char	**ft_split(char *s, char c);
void	ft_error_lst(t_list *p, int k);
char	*get_next_line(int fd);
void	sa(t_list **lst, int k);
void	sb(t_list **lst, int k);
void	ra(t_list **lst, int k);
void	rb(t_list **lst, int k);
void	rra(t_list **lst, int k);
void	rrb(t_list **lst, int k);
void	pa(t_list **a, t_list **b, int k);
void	pb(t_list **b, t_list **a, int k);
void	rrr(t_list **a, t_list **b, int k);
int		a_is_sorted(t_list *nums);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_strlen( char *str);
int		check_dig_sign(char **av);
int		repeat_of_numbers(t_list *p);
t_list	*concat_arg(char **av);
void	rr(t_list **a, t_list **b, int k);
int		lstsize(t_list **lst);
int		ft_acses(t_list *stack_a);
void	lstadd_front(t_list **lst, t_list *new);
void	lstadd_back(t_list **lst, t_list *new);
t_list	*lstnew(int content);

#endif
