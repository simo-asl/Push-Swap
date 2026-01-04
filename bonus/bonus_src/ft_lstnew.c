/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symo <symo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:11:24 by mel-asla          #+#    #+#             */
/*   Updated: 2026/01/04 06:41:59 by symo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_list	*ft_lstnew(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}
