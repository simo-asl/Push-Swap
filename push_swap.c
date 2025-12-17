/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:14:33 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/17 16:38:25 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*int	main(int ac, char *av[])
{
	long	res;

	if (ac == 1)
		return (0);

}
*/
int	main(int ac, char **av)
{
	t_list	*stack;
	t_list	*tmp;

	if (ac < 2)
		return (0);
	stack = ft_input_pars(ac, av);
	//test
	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_lstclear(&stack);
	return (0);
}
