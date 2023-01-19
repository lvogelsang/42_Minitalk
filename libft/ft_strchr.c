/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:00:48 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/29 10:27:10 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strchr() function locates the first occurrence of c (converted to a
// char) in the string pointed to by s.  The terminating null character is
// considered to be part of the string; therefore if c is ‘\0’, the functions
// locate the terminating ‘\0’.

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = c % 256;
	if (*s == c)
	{
		return ((char *)s);
	}
	s++;
	while (*(s - 1))
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
