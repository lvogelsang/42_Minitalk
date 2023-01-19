/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:42:34 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/28 10:49:58 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a new string, which is the result of the concatenation of s1 and s2.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*concat;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	concat = (char *)malloc(len * sizeof(char));
	if (concat == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(concat, s1, ft_strlen(s1) + 1);
	ft_strlcpy(concat + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (concat);
}
