/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inpust_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:09:37 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/10 11:09:39 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_input_pars(int ac, char **av)
{
	t_list  *stack;
	char	**split;
	long	nb;
	int		j;
	int		i;

	i = 1;
	stack = NULL;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			error_exit();
		j = 0;
		while (split[j])
		{
			if (!ft_isnumber(split[j]))
				error_exit();
			nb = ft_atol(split[j]);
			if (nb < INT_MIN || nb > INT_MAX)
				error_exit();
			ft_lstadd_back(&stack, ft_lstnew((int)nb));
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	if (ft_dup_check_stack(stack))
		error_exit();
	return (stack);
}