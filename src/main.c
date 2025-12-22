/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:14:33 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/20 11:46:15 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack;

	if (ac < 2)
		return (0);
	stack = ft_input_pars(ac, av);
	if (!stack)
		return (0);
	if (!stack || ft_lstsize(stack) <= 1 || is_sorted(stack))
	{
		ft_lstclear(&stack);
		return (0);
	}
	assign_indices(stack);
	push_swap_sort(&stack);
	ft_lstclear(&stack);
	return (0);
}
