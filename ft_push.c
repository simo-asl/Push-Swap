/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:09:20 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/17 15:15:47 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = *(src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_list **a, t_list **b)
{
	ft_push(b, a);
}

void	pb(t_list **b, t_list **a)
{
	ft_swap(a, b);
}
