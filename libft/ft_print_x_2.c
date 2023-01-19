/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:36:27 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/21 11:40:26 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft__precision_x(t_format format, char *x_str, unsigned int x)
{
	char	*x_str_format;

	if (format.precision == 0 && x == 0)
	{
		x_str_format = (char *)malloc(sizeof(char));
		if (x_str_format == NULL)
			return (NULL);
		x_str_format[0] = '\0';
	}
	else if ((format.precision > (int)ft_strlen(x_str))
		|| ((format.hash) && (format.precision > ((int)ft_strlen(x_str) - 2))
			&& x != 0))
		x_str_format = ft_precision_x_2(format, x_str, x);
	else
		x_str_format = ft_strdup(x_str);
	if (x_str_format == NULL)
		return (NULL);
	return (x_str_format);
}

char	*ft_precision_x_2(t_format format, char *x_str, unsigned int x)
{
	char	*x_str_format;
	char	*zero;
	int		i;

	i = 0;
	if (format.hash && x != 0)
		i = 2;
	zero = ft_precision_zero_x(format, x_str, i);
	if (zero == NULL)
		return (NULL);
	x_str_format = ft_strjoin(zero, x_str + i);
	free (zero);
	if (x_str_format == NULL)
		return (NULL);
	return (x_str_format);
}

char	*ft_precision_zero_x(t_format format, char *x_str, int i)
{
	char	*zero;
	int		count;
	int		j;

	count = format.precision - ft_strlen(x_str);
	zero = (char *)malloc((count + i * 2 + 1) * sizeof(char));
	if (zero == NULL)
		return (NULL);
	j = 0;
	if (i == 2)
	{
		zero[0] = x_str[0];
		zero[1] = x_str[1];
		j = j + 2;
	}
	while (j < (count + i * 2))
	{
		zero[j] = '0';
		j++;
	}
	zero[j] = '\0';
	return (zero);
}

void	ft_width_x(t_format format, char *x_str, unsigned int x)
{
	int	i;

	i = 0;
	if (format.zero && !(format.minus)
		&& (format.hash) && x != 0)
	{
		ft_putchar_fd(x_str[i++], 1);
		ft_putchar_fd(x_str[i++], 1);
		format.width = format.width - 2;
	}
	ft_width_adjustment(format, &x_str[i]);
}
