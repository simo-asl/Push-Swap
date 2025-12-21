/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:21:00 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/21 18:21:00 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	execute_instruction(char *line, t_list **a, t_list **b)
{
	if (!line)
		return ;
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_swap(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_swap(b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_push(b, a);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_push(a, b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_rotate(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rotate(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		ft_reverse_rotate(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		ft_reverse_rotate(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
	else
		error_exit();
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*line;

	if (ac < 2)
	{
		write(1, "OK\n", 3);
		return (0);
	}
	a = ft_input_pars(ac, av);
	b = NULL;
	line = get_next_line(0);
	while (line)
	{
		execute_instruction(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && ft_lstsize(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
