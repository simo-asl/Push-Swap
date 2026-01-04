/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:50:58 by mel-asla          #+#    #+#             */
/*   Updated: 2025/12/17 16:46:09 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (res > (LONG_MAX - (*str - '0')) / 10)
			return (1337 + 2147483690);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
