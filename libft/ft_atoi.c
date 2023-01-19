/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:09:45 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/29 11:01:40 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The atoi() function converts the initial portion of the string pointed to
// by str to int representation.

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	x;

	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	x = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		x = x * 10;
		x = x + (str[i] - 48);
		i++;
	}
	x = x * sign;
	return (x);
}
