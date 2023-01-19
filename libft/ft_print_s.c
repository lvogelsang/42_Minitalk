/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:50:44 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/21 11:53:19 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print functions for conversion type 's'. This type considers the '-' flag
// and width and precision specifications.

int	ft_print_s(t_format format, char *s)
{
	char	*s_str;
	int		len;

	if (!(s))
		s_str = ft_strdup("(null)");
	else
		s_str = ft_strdup(s);
	if (s_str == NULL)
		return (0);
	len = ft_format_s(format, s_str);
	free (s_str);
	return (len);
}

int	ft_format_s(t_format format, char *s_str)
{
	int	i;
	int	len;

	i = ft_strlen(s_str);
	if (format.dot)
	{
		if (format.precision < i)
		{
			s_str[format.precision] = '\0';
			i = format.precision;
		}
	}
	if (format.width > i)
	{
		ft_width_adjustment(format, s_str);
		len = format.width;
	}
	else
	{
		ft_putstr_fd(s_str, 1);
		len = i;
	}
	return (len);
}
