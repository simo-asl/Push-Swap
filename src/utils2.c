/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:11:15 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/20 15:49:01 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_to_top_a(t_list **a, int pos)
{
	int	size;

	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

void	rotate_to_top_b(t_list **b, int pos)
{
	int	size;

	size = ft_lstsize(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

void	push_back_to_a(t_list **a, t_list **b)
{
	int	pos;

	while (*b)
	{
		pos = get_pos_max(*b);
		rotate_to_top_b(b, pos);
		pa(a, b);
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
