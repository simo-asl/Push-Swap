/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:21:00 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/23 01:58:59 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

//parsing functions
long	ft_atol(const char *str);
int		ft_dup_check_stack(t_list *stack);
int		ft_isnumber(char *s);
void	error_exit(t_list **a, t_list **b, char **split);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *d, const char *s, size_t size);
t_list	*ft_input_pars(int ac, char **av);
int		is_sorted(t_list *a);
void	ft_free_split(char **split);

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

//get_next_line
char	*get_next_line(int fd, char **buffer);

#endif
