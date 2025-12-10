/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:42:54 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/07 09:54:54 by mel-asla         ###   ########.fr       */
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
	struct s_list	*next;
}	t_list;

//parsing functions
long	ft_atol(const char *str);
int		ft_dup_check_stack(t_list *stack);
int		ft_isnumber(char *s);
void	error_exit(void);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *d, const char *s, size_t size);
t_list	*ft_input_pars(int ac, char **av);

//list functions
t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);

#endif
