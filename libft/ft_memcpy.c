/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:08:00 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/12 11:29:18 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memcpy() function copies n bytes from memory area src to memory area
//dst.  If dst and src overlap, behavior is undefined.

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_copy;
	unsigned char	*src_copy;

	dst_copy = (unsigned char *)dst;
	src_copy = (unsigned char *)src;
	if (!n || (!dst && ! src))
	{
		return (dst);
	}
	while (n)
	{
		*dst_copy = *src_copy;
		dst_copy++;
		src_copy++;
		n--;
	}
	return (dst);
}
