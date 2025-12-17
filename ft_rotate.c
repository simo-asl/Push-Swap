/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:21:55 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/17 16:42:00 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_list **a)
{
	ft_rotate(a);
}

void	rb(t_list **b)
{
	ft_rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
