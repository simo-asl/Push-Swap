/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:42:54 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/17 14:53:46 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				flag;
	struct s_list	*next;
}	t_list;

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_push;

//parsing functions
long	ft_atol(const char *str);
int		ft_dup_check_stack(t_list *stack);
int		ft_isnumber(char *s);
void	error_exit(void);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *d, const char *s, size_t size);
t_list	*ft_input_pars(int ac, char **av);
int		is_sorted(t_list *a);

//list functions
t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);

//instruction functions
void	ft_rotate(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	ft_swap(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ft_push(t_list **src, t_list **dest);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ft_reverse_rotate(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

//utils
int		*stack_to_array(t_list *stack, int size);
void	sort_ints(int *arr, int n);
void	assign_indices(t_list *stack);
int		get_pos_if(t_list *stack, int max_index);
int		get_pos_max(t_list *stack);

//sorting functions
void	sort_three(t_list **a);
void	push_small_to_b(t_list **a, t_list **b);
void	sort_five_or_four(t_list **a, t_list **b);
void	sort_small(t_list **a, t_list **b);
void	rotate_to_top_a(t_list **a, int pos);
void	rotate_to_top_b(t_list **b, int pos);
void	push_back_to_a(t_list **a, t_list **b);
void	push_chunk(t_list **a, t_list **b, int current_max, int chunk_size);
void	chunk_sort(t_list **a, t_list **b, int n);
void	push_swap_sort(t_list **a);

//quicksort functions
void	begin_sorting(t_list **stack1, t_list **stack2, t_push *push, int count);
void	find_next(t_list **stack1, t_list **stack2, t_push *push);
void	quick_a(t_list **stack1, t_list **stack2, t_push *push);
void	quick_b(t_list **stack1, t_list **stack2, t_push *push);
void	quick_sort(t_list **stack1, t_list **stack2, int count);
t_list	*find_min_lst(t_list **stack);
t_list	*find_max_lst(t_list **stack);
int		check_sorting_a(t_list **stack1, int count);

#endif
