/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:25:13 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/17 17:14:54 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*before_last;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	write(1, "rrr\n", 4);
	ft_reverse_rotate(b);
}
