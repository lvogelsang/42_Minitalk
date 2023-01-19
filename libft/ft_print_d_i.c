/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:43:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/21 10:41:15 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print functions for the conversion types 'd' and 'i'. These types consider 
// the '+', ' ', '-', & '0' flags as well as width and
// precision specifications.

int	ft_print_d_i(t_format format, int n)
{
	char	*d_i_str;
	int		i;
	int		len;

	d_i_str = ft_str_d_i(format, n);
	if (d_i_str == NULL)
		return (0);
	if (format.dot)
		format.zero = 0;
	i = ft_strlen(d_i_str);
	if (format.width > i)
	{
		len = format.width;
		ft_width_d_i(format, d_i_str, n);
	}
	else
	{
		len = i;
		ft_putstr_fd(d_i_str, 1);
	}
	free (d_i_str);
	return (len);
}

char	*ft_str_d_i(t_format format, int n)
{
	char	*d_i_str_format;
	char	*d_i_str_sign;
	int		x;

	d_i_str_sign = ft_sign_d_i(format, n);
	if (d_i_str_sign == NULL)
		return (NULL);
	if (format.dot)
	{
		x = 0;
		if (format.plus || format.space || (n < 0))
			x = 1;
		d_i_str_format = ft_precision_d_i(format, d_i_str_sign, n, x);
	}
	else
		d_i_str_format = ft_strdup(d_i_str_sign);
	free (d_i_str_sign);
	if (d_i_str_format == NULL)
		return (NULL);
	return (d_i_str_format);
}

char	*ft_sign_d_i(t_format format, int n)
{
	char	*d_i_str_sign;
	char	*sign;
	char	*temp;

	if ((format.plus || format.space) && n >= 0)
	{
		if (format.plus)
			sign = "+";
		else if (format.space)
			sign = " ";
		temp = ft_itoa(n);
		if (temp == NULL)
			return (NULL);
		d_i_str_sign = ft_strjoin(sign, temp);
		free (temp);
	}
	else
		d_i_str_sign = ft_itoa(n);
	if (d_i_str_sign == NULL)
		return (NULL);
	return (d_i_str_sign);
}

void	ft_width_d_i(t_format format, char *d_i_str, int n)
{
	int	x;

	x = 0;
	if (format.zero && !(format.minus)
		&& (format.plus || format.space || (n < 0)))
	{
		ft_putchar_fd(d_i_str[x], 1);
		x++;
		format.width--;
	}
	ft_width_adjustment(format, &d_i_str[x]);
}
