/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:06:07 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/08 11:43:24 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strnstr() function locates the first occurrence of the null-terminated
// string needle in the string haystack, where not more than len characters
// are searched.

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[i] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] && ft_strlen(needle) + i <= len)
	{
		if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
		{
			haystack = haystack + i;
			return ((char *)haystack);
		}
		i++;
	}
	return (NULL);
}
