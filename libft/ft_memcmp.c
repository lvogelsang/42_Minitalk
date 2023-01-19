/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:30:22 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/08 10:37:22 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memcmp() function compares byte string s1 against byte string s2.  Both
// strings are assumed to be n bytes long.

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s1 == *(unsigned char *)s2)
		{
			i++;
			if (i == n)
			{
				break ;
			}
			else
			{
				s1++;
				s2++;
			}
		}
		else
			break ;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
