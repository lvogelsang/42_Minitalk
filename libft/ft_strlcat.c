/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:33:07 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/30 14:48:29 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Strlcat() appends string src to the end of dst.  It will append at most
// dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
// dstsize is 0 or the original dst string was longer than dstsize.

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	i;

	x = ft_strlen(dst);
	if (x > dstsize)
	{
		x = dstsize;
	}
	i = 0;
	while (src[i] && i + x + 1 < dstsize)
	{
		dst[x + i] = src[i];
		i++;
	}
	if (x < dstsize)
	{
		dst[x + i] = '\0';
	}
	return (x + ft_strlen(src));
}
