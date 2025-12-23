/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:23:01 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/23 03:05:38 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_min_lst(t_list **stack)
{
	t_list	*min;
	t_list	*tmp;

	min = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index < min->index)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*find_max_lst(t_list **stack)
{
	t_list	*max;
	t_list	*tmp;

	max = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	check_sorting_a(t_list **stack1, int count)
{
	int	len;

	len = ft_lstsize(*stack1);
	if (len != count)
		return (0);
	if (is_sorted(*stack1) == 0)
		return (0);
	return (1);
}

void	push_swap_sort(t_list **a)
{
	int			n;
	t_list		*b;

	b = NULL;
	n = ft_lstsize(*a);
	if (n <= 5)
	{
		sort_small(a, &b);
		return ;
	}
	quick_sort(a, &b, n);
}
