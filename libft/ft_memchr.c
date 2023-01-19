/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:02:37 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/27 15:47:35 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memchr() function locates the first occurrence of c (converted to an
// unsigned char) in string s.

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
		{
			return ((void *)s);
		}
		else
		{
			i++;
			s++;
		}
	}
	return (NULL);
}
