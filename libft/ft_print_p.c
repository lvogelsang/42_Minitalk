/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:47:15 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/21 09:35:37 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print functions for the conversion type 'p'. This type considers
// the '-' & '0' flags as well as width specifications.

// The address of a pointer is in hexadecimal format, so we use similar
// methods to the conversion types 'x' & 'X'. The main difference is that
// we use size_t instead of unsigned int as size_t can get as big as the
// addressable memory space, while unsigned int has a minimum range.

int	ft_print_p(t_format format, size_t p)
{
	char	*p_str;
	int		len;
	int		x;

	p_str = ft_str_p(p);
	if (p_str == NULL)
		return (0);
	len = ft_strlen(p_str);
	if (format.width > len)
	{
		len = format.width;
		x = 0;
		if (format.zero && !(format.minus))
		{
			ft_putchar_fd(p_str[x++], 1);
			ft_putchar_fd(p_str[x++], 1);
		}
		ft_width_adjustment(format, &p_str[x]);
	}
	else
		ft_putstr_fd(p_str, 1);
	free (p_str);
	return (len);
}

char	*ft_str_p(size_t p)
{
	char	*prefix;
	char	*p_str;
	char	*temp;

	prefix = "0x";
	temp = ft_itoa_p(p);
	p_str = ft_strjoin(prefix, temp);
	free (temp);
	if (p_str == NULL)
		return (NULL);
	return (p_str);
}

char	*ft_itoa_p(size_t p)
{
	char	*hex_base;
	char	*p_str;
	int		i;

	i = ft_digitcount_p(p);
	p_str = (char *)malloc((i + 1) * sizeof(char));
	if (p_str == NULL)
		return (NULL);
	p_str[i] = '\0';
	if (p == 0)
		p_str[0] = '0';
	hex_base = "0123456789abcdef";
	while (p)
	{
		i--;
		p_str[i] = hex_base[p % 16];
		p = p / 16;
	}
	return (p_str);
}

int	ft_digitcount_p(size_t p)
{
	int	i;

	if (p == 0)
		return (1);
	i = 0;
	while (p)
	{
		p = p / 16;
		i++;
	}
	return (i);
}
