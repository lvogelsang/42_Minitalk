/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:41:44 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/29 10:40:12 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strncmp() functions lexicographically compare the null-
// terminated strings s1 and s2.
// The strncmp() function compares not more than n characters.  Because
// strncmp() is designed for comparing strings rather than binary data,
// characters that appear after a ‘\0’ character are not compared.

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			i++;
		}
		else
		{
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
	}
	return (0);
}
