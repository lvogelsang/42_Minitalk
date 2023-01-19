/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:28:17 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/12 10:19:32 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a substring from the string s. The substring begins at index start
// and is of maximum size len.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start >= ft_strlen(s) || start < 0)
		len = 1;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start + 1;
	else if (len < 0)
	{
		len = ft_strlen(s) + 1;
		start = 0;
	}
	else
		len = len + 1;
	sub = (char *)malloc(len * sizeof(char const));
	if (sub == NULL)
		return (NULL);
	if (len == 1)
	{
		sub[0] = 0;
		return (sub);
	}
	ft_strlcpy(sub, s + start, len);
	return (sub);
}
