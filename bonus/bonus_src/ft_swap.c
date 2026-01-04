/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:02:09 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/17 17:15:20 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_swap(t_list **stack)
{
	int	val_tmp;
	int	ind_tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	val_tmp = (*stack)->value;
	ind_tmp = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value = val_tmp;
	(*stack)->next->index = ind_tmp;
}

void	sa(t_list **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
}
