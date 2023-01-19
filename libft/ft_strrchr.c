/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:25:15 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/12 11:53:15 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strrchr() function is identical to strchr(), except it locates the last
// occurrence of c.

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	c = c % 256;
	i = ft_strlen(s);
	if (c == '\0')
	{
		return ((char *)s + i);
	}
	while (i + 1)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (NULL);
}
