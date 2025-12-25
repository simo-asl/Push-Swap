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

#include "../push_swap.h"

void	ft_parstr(t_list **stack, char *str)
{
	char	**split;
	long	nb;
	int		j;

	split = ft_split(str, ' ');
	j = 0;
	if (!split || *split == NULL)
		error_exit(stack, NULL, split);
	while (split[j])
	{
		if (!ft_isnumber(split[j]))
			error_exit(stack, NULL, split);
		nb = ft_atol(split[j]);
		if (nb < INT_MIN || nb > INT_MAX)
			error_exit(stack, NULL, split);
		ft_lstadd_back(stack, ft_lstnew((int)nb));
		j++;
	}
	ft_free_split(split);
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
		error_exit(&stack, NULL, NULL);
	return (stack);
}

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
