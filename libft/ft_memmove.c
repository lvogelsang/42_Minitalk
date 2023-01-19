/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:58:53 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/12 11:17:14 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memmove() function copies len bytes from string src to string dst.
//The two strings may overlap; the copy is always done in a non-destructive
//manner.

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
	{
		while (len)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
