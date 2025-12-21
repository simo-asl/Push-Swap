/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:09:20 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/17 17:11:40 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_list **a, t_list **b)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a)
{
	write(1, "pb\n", 3);
	ft_push(a, b);
}
