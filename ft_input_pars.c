/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:09:37 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/17 18:26:07 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parstr(t_list **stack, char *str)
{
	char	**split;
	long	nb;
	int		j;

	split = ft_split(str, ' ');
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
		ft_lstadd_back(stack, ft_lstnew((int)nb));
		free(split[j]);
		j++;
	}
	free(split);
}

t_list	*ft_input_pars(int ac, char **av)
{
	t_list	*stack;
	int		i;

	i = 1;
	stack = NULL;
	while (i < ac)
	{
		ft_parstr(&stack, av[i]);
		i++;
	}
	if (ft_dup_check_stack(stack))
		error_exit();
	return (stack);
}
