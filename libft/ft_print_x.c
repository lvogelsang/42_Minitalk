/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:20:46 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/21 09:38:16 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print functions for the conversion types 'x' & 'X'. These types 
// consider the '-', '0', & '#' flags as well as width and 
// precision specifications.

// The base characters for hexadecimal are "0123456789abcdef" and 
// "0123456789ABCDEF", respectively. 
// For conversion from decimal to hexadecimal, keep dividing a decimal number 
// by 16. The hex value of that decimal number is the sequence of remainders 
// (in hex) from the last to the first.

int	ft_print_x(t_format format, unsigned int x)
{
	char	*x_str;
	int		i;
	int		len;

	x_str = ft_str_x(format, x);
	if (x_str == NULL)
		return (0);
	if (format.dot)
		format.zero = 0;
	i = ft_strlen(x_str);
	if (format.width > i)
	{
		len = format.width;
		ft_width_x(format, x_str, x);
	}
	else
	{
		len = i;
		ft_putstr_fd(x_str, 1);
	}
	free (x_str);
	return (len);
}

char	*ft_str_x(t_format format, unsigned int x)
{
	char	*x_str;
	char	*x_str_format;

	x_str = ft_str_x_2(format, x);
	if (x_str == NULL)
		return (NULL);
	if (format.dot)
		x_str_format = ft__precision_x(format, x_str, x);
	else
		x_str_format = ft_strdup(x_str);
	free (x_str);
	if (x_str_format == NULL)
		return (NULL);
	return (x_str_format);
}

char	*ft_str_x_2(t_format format, unsigned int x)
{
	char	*hex_base;
	char	*prefix;
	char	*temp;
	char	*x_str;

	if (format.type == 'x')
		hex_base = "0123456789abcdef";
	else if (format.type == 'X')
		hex_base = "0123456789ABCDEF";
	if (format.hash && x != 0)
	{
		if (format.type == 'x')
			prefix = "0x";
		else if (format.type == 'X')
			prefix = "0X";
		temp = ft_itoa_x(x, hex_base);
		x_str = ft_strjoin(prefix, temp);
		free (temp);
	}
	else
		x_str = ft_itoa_x(x, hex_base);
	if (x_str == NULL)
		return (NULL);
	return (x_str);
}

char	*ft_itoa_x(unsigned int x, char *hex_base)
{
	char	*x_str;
	int		i;

	i = ft_digitcount_x(x);
	x_str = (char *)malloc((i + 1) * sizeof(char));
	if (x_str == NULL)
		return (NULL);
	x_str[i] = '\0';
	if (x == 0)
		x_str[0] = '0';
	if (x == 80000000)
	{
		x_str = "80000000";
		return (x_str);
	}
	while (x)
	{
		i--;
		x_str[i] = hex_base[x % 16];
		x = x / 16;
	}
	return (x_str);
}

int	ft_digitcount_x(unsigned int x)
{
	int	i;

	if (x == 0)
		return (1);
	if (x == 80000000)
		return (8);
	i = 0;
	while (x)
	{
		x = x / 16;
		i++;
	}
	return (i);
}
