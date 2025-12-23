/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:21:00 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/23 01:40:35 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static int	valid_instra(char *line)
{
	if (!ft_strcmp(line, "ss\n") || !ft_strcmp(line, "sa\n"))
		return (1);
	else if (!ft_strcmp(line, "sb\n") || !ft_strcmp(line, "pa\n"))
		return (1);
	else if (!ft_strcmp(line, "ra\n") || !ft_strcmp(line, "pb\n"))
		return (1);
	else if (!ft_strcmp(line, "rb\n") || !ft_strcmp(line, "rr\n"))
		return (1);
	else if (!ft_strcmp(line, "rrb\n") || !ft_strcmp(line, "rra\n"))
		return (1);
	else if (!ft_strcmp(line, "rrr\n"))
		return (1);
	else
		return (0);
}

/*
sa\n  = 's'(115) + 'a'(97)  + 10 = 222
sb\n  = 's'(115) + 'b'(98)  + 10 = 223
ss\n  = 's'(115) + 's'(115) + 10 = 240
pa\n  = 'p'(112) + 'a'(97)  + 10 = 219
pb\n  = 'p'(112) + 'b'(98)  + 10 = 220
ra\n  = 'r'(114) + 'a'(97)  + 10 = 221
rb\n  = 'r'(114) + 'b'(98)  + 10 = 222 + 100 = 320
rr\n  = 'r'(114) + 'r'(114) + 10 = 238
rra = 'r'(114) + 'r'(114) + 'a'(97) = 325 no need to add the 10 
rrb = 'r'(114) + 'r'(114) + 'b'(98) = 326
rrr = 'r'(114) + 'r'(114) + 'r'(114) = 342
*/

static void	line_sum(int sum, t_list **a, t_list **b)
{
	if (sum == 222 || sum == 240)
		ft_swap(a);
	if (sum == 223 || sum == 240)
		ft_swap(b);
	if (sum == 219)
		ft_push(b, a);
	if (sum == 220)
		ft_push(a, b);
	if (sum == 221 || sum == 238)
		ft_rotate(a);
	if (sum == 1337 || sum == 238)
		ft_rotate(b);
	if (sum == 325 || sum == 342)
		ft_reverse_rotate(a);
	if (sum == 326 || sum == 342)
		ft_reverse_rotate(b);
}

static void	do_instruction(char *line, t_list **a, t_list **b)
{
	int	sum;

	if (!line)
		return ;
	if (!valid_instra(line))
		error_exit();
	sum = line[0];
	sum += line[1];
	sum += line[2];
	if (line[0] == 'r' && line[1] == 'b')
		sum += 1115;
	line_sum(sum, a, b);
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
		do_instruction(line, &a, &b);
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
