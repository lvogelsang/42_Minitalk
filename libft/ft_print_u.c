/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:44:36 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/21 10:26:25 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print functions for the conversion type 'u'. This type considers the
// '-' & '0' flags and width and precision specifications.

// If a negative value is parsed as an unsigned integer, that value
// is converted to its positive counterpart, i.e., 2^32 - u.
// So, in binary, -u and 2^32 - u are identical.
// Therefore, we cannot use the standard digitcount and itoa functions.

int	ft_print_u(t_format format, unsigned int u)
{
	char	*u_str;
	int		i;
	int		len;

	u_str = ft_str_u(format, u);
	if (u_str == NULL)
		return (0);
	if (format.dot)
		format.zero = 0;
	i = ft_strlen(u_str);
	if (format.width > i)
	{
		len = format.width;
		ft_width_adjustment(format, u_str);
	}
	else
	{
		len = i;
		ft_putstr_fd(u_str, 1);
	}
	free (u_str);
	return (len);
}

char	*ft_str_u(t_format format, unsigned int u)
{
	char	*u_str;
	char	*u_str_format;

	u_str = ft_itoa_u(u);
	if (u_str == NULL)
		return (NULL);
	if (format.dot)
		u_str_format = ft_precision_u(format, u_str, u);
	else
		u_str_format = ft_strdup(u_str);
	free (u_str);
	if (u_str_format == NULL)
		return (NULL);
	return (u_str_format);
}

char	*ft_itoa_u(unsigned int u)
{
	char	*u_str;
	int		i;

	i = ft_digitcount_u(u);
	u_str = (char *)malloc((i + 1) * sizeof(char));
	if (u_str == NULL)
		return (NULL);
	u_str[i] = '\0';
	if (u == 0)
		u_str[0] = '0';
	while (u)
	{
		i--;
		u_str[i] = u % 10 + 48;
		u = u / 10;
	}
	return (u_str);
}

int	ft_digitcount_u(unsigned int u)
{
	int	i;

	if (u == 0)
		return (1);
	i = 0;
	while (u)
	{
		i++;
		u = u / 10;
	}
	return (i);
}
