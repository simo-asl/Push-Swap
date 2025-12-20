/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:50:26 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/20 13:52:03 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_list *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_exit();
	i = 0;
	while (stack && i < size)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

void	sort_ints(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_indices(t_list *stack)
{
	int		size;
	int		*arr;
	int		i;
	t_list	*tmp;

	size = ft_lstsize(stack);
	arr = stack_to_array(stack, size);
	sort_ints(arr, size);
	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size && arr[i] != tmp->value)
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
	free(arr);
}

int	get_pos_if(t_list *stack, int max_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index <= max_index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	get_pos_max(t_list *stack)
{
	int	max;
	int	pos;
	int	i;

	if (!stack)
		return (-1);
	max = stack->index;
	i = 0;
	pos = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}
