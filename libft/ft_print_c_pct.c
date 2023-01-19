/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:48:45 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/21 11:54:14 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print functions for conversion type '%' and 'c'. These types accept the
// '-' and '0' flags as well as width specifications.

int	ft_print_c_pct(t_format format, va_list *args)
{
	char	c;
	int		len;

	if (format.type == 'c')
		c = va_arg(*args, int);
	else if (format.type == '%')
		c = '%';
	if (format.width > 1)
	{
		len = format.width;
		ft_format_c_pct(format, c);
	}
	else
	{
		ft_putchar_fd(c, 1);
		len = 1;
	}
	return (len);
}

void	ft_format_c_pct(t_format format, int c)
{
	if (format.minus)
		ft_putchar_fd(c, 1);
	while (--format.width)
	{
		if (format.zero && !(format.minus))
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (!(format.minus))
		ft_putchar_fd(c, 1);
}
