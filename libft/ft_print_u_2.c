/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:18:30 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/21 10:28:09 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_u(t_format format, char *u_str, unsigned int u)
{
	char	*u_str_format;

	if (format.precision == 0 && u == 0)
	{
		u_str_format = (char *)malloc(sizeof(char));
		if (u_str_format == NULL)
			return (NULL);
		u_str_format[0] = '\0';
	}
	else if (format.precision > (int)ft_strlen(u_str))
		u_str_format = ft_precision_u_2(format, u_str);
	else
		u_str_format = ft_strdup(u_str);
	if (u_str_format == NULL)
		return (NULL);
	return (u_str_format);
}

char	*ft_precision_u_2(t_format format, char *u_str)
{
	char	*u_str_format;
	char	*zero;
	int		count;
	int		i;

	count = format.precision - ft_strlen(u_str);
	zero = (char *)malloc((count + 1) * sizeof(char));
	if (zero == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		zero[i] = '0';
		i++;
	}
	zero[i] = '\0';
	u_str_format = ft_strjoin(zero, u_str);
	free (zero);
	if (u_str_format == NULL)
		return (NULL);
	return (u_str_format);
}
