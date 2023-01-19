/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:40:02 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/29 13:56:07 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a string representing the integer received as an argument.

#include "libft.h"

int	ft_digitcount(int n)
{
	int	count;

	if (n == 0)
	{
		return (1);
	}
	count = 0;
	if (n < 0)
	{
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_numstr(char *numstr, int n, int count)
{
	numstr[count] = '\0';
	while (n != 0)
	{
		numstr[count - 1] = (n % 10) + 48;
		n = n / 10;
		count--;
	}
	return (numstr);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*numstr;

	count = ft_digitcount(n);
	numstr = (char *)malloc((count + 1) * sizeof(char));
	if (numstr == NULL)
	{
		return (NULL);
	}
	if (n == 0)
	{
		numstr[0] = '0';
	}
	if (n == -2147483648)
	{
		numstr[1] = '2';
		n = -147483648;
	}
	if (n < 0)
	{
		numstr[0] = '-';
		n = n * (-1);
	}
	ft_numstr(numstr, n, count);
	return (numstr);
}
