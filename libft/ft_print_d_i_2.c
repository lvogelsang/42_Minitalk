/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:20:42 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/21 11:38:43 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_d_i(t_format format, char *d_i_str, int n, int x)
{
	char	*d_i_str_format;

	if (format.precision == 0 && n == 0)
	{
		d_i_str_format = ft_strdup(d_i_str);
		if (d_i_str_format == NULL)
			return (NULL);
		d_i_str_format[x] = '\0';
	}
	else if ((format.precision > (int)ft_strlen(d_i_str))
		|| ((format.plus || format.space || (n < 0))
			&& (format.precision == (int)ft_strlen(d_i_str))))
		d_i_str_format = ft_precision_d_i_2(format, d_i_str, n, x);
	else
		d_i_str_format = ft_strdup(d_i_str);
	if (d_i_str_format == NULL)
		return (NULL);
	return (d_i_str_format);
}

char	*ft_precision_d_i_2(t_format format, char *d_i_str, int n, int x)
{
	char	*d_i_str_format;
	char	*zero;

	zero = ft_precision_zero_d_i(format, d_i_str, n, x);
	if (zero == NULL)
		return (NULL);
	d_i_str_format = ft_strjoin(zero, d_i_str + x);
	free (zero);
	if (d_i_str_format == NULL)
		return (NULL);
	return (d_i_str_format);
}

char	*ft_precision_zero_d_i(t_format format, char *d_i_str, int n, int x)
{
	char	*zero;
	int		count;
	int		i;

	count = format.precision - ft_strlen(d_i_str);
	zero = (char *)malloc((count + x * 2 + 1) * sizeof(char));
	if (zero == NULL)
		return (NULL);
	i = 0;
	if (format.plus || format.space || (n < 0))
	{
		zero[0] = d_i_str[0];
		i++;
	}
	while (i < (count + x * 2))
	{
		zero[i] = '0';
		i++;
	}
	zero[i] = '\0';
	return (zero);
}
