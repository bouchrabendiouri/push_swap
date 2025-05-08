

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int				cost_rb;
	int				cost_rrb;
	int				cost_ra;
	int				cost_rra;
	int				total_cost;
	int				do_rra;
	int				do_rrb;
	struct s_list	*next;
}	t_list;

typedef struct s_comb{
	int	one;
	int	two;
	int	three;
	int	four;
}	t_comb;

void	sort_five(t_list **stack_a, t_list **b);
int		ft_atoi(char *str, t_list *p);
char	**ft_split(char *s, char c);
void	ft_error_lst(t_list *p, int k);
char	*get_next_line(int fd);
void	sa(t_list **lst, int k);
void	sb(t_list **lst, int k);
void	ra(t_list **lst, int k);
void	rb(t_list **lst, int k);
void	rr(t_list **a, t_list **b, int k);
void	rra(t_list **lst, int k);
void	rrb(t_list **lst, int k);
void	rrr(t_list **stack_a, t_list **stack_b, int k);
void	pa(t_list **a, t_list **b, int k);
void	pb(t_list **b, t_list **a, int k);
int		a_is_sorted(t_list *nums);
void	lstadd_back(t_list **lst, t_list *new);
t_list	*lstnew(int content);
void	lstadd_front(t_list **lst, t_list *new);
int		lstsize(t_list **lst);
void	sort(t_list **stack_a, t_list **stack_b);
int		get_min_element(t_list *stack_a);
int		get_index_in_a(t_list *stack_a, int element);
t_list	*get_greater_number(t_list *stack_a, int element);
void	min_to_top(t_list **stack_a);
void	cost_ra(t_list *stack_a, t_list *stack_b);
void	cost_rra(t_list *stack_a, t_list *stack_b);
void	cost_rb(t_list *stack_b);
void	cost_rrb(t_list *stack_b);
void	reset_values(t_list *stack_b);
int		min(int a, int b);
int		max(int a, int b);
int		min_cost(int a, int b, int c, int d);
void	total_cost(t_list *stack_b);
t_list	*get_min_cost_element(t_list *stack_b);
int		acses(t_list *stack_a);
int		sort_three_sa_rra(t_list **a);
int		sort_three_sa_ra(t_list **a);
int		sort_three_sa_and_write(t_list **a);
int		sort_three_ra_and_write(t_list **a);
int		sort_three_rra_and_write(t_list **a);
int		sort_three(t_list **a);
void	init_index(t_list *stack_a);
int		ft_strlen( char *str);
void	push_swap(t_list **stack_a);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif
