/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:21:01 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/20 13:39:18 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	int	x;
	int	y;
	int	z;

	if (is_sorted(*a))
		return ;
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	push_small_to_b(t_list **a, t_list **b)
{
	int		pos;
	int		min;
	t_list	*tmp;

	while (ft_lstsize(*a) > 3)
	{
		pos = 0;
		min = (*a)->index;
		tmp = *a;
		while (tmp)
		{
			if (tmp->index < min)
				min = tmp->index;
			tmp = tmp->next;
		}
		tmp = *a;
		while (tmp && tmp->index != min)
		{
			pos++;
			tmp = tmp->next;
		}
		rotate_to_top_a(a, pos);
		pb(b, a);
	}
}

void	sort_five_or_four(t_list **a, t_list **b)
{
	push_small_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_small(t_list **a, t_list **b)
{
	int		size;
	int		pos;
	int		min;
	t_list	*tmp;

	size = ft_lstsize(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	if (size == 4 || size == 5)
		sort_five_or_four(a, b);
}
