/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:33:15 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/20 18:02:16 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_list **a, t_list **b, int n)
{
	int	chunks;
	int	chunk_size;
	int	i;
	int	current_max;

	i = 0;
	if (n > 100)
		chunks = 11;
	else
		chunks = 5;
	chunk_size = n / chunks;
	current_max = chunk_size - 1;
	while (i < chunks)
	{
		push_chunk(a, b, current_max, chunk_size);
		i++;
		current_max += chunk_size;
		if (i == chunks - 1)
			current_max = n - 1;
	}
}

void	push_chunk(t_list **a, t_list **b, int current_max, int chunk_size)
{
	int	pos;

	while (1)
	{
		pos = get_pos_if(*a, current_max);
		if (pos == -1)
			break ;
		rotate_to_top_a(a, pos);
		if ((*a)->index <= current_max - (chunk_size / 2))
			pb(b, a);
		else
		{
			pb(b, a);
			rb(b);
		}
	}
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
	chunk_sort(a, &b, n);
	push_back_to_a(a, &b);
}
