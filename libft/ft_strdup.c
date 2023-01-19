/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:58:28 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/12 12:47:09 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strdup() function allocates sufficient memory for a copy of the string
// s1, does the copy, and returns a pointer to it.

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*copy;

	size = ft_strlen(s1) + 1;
	copy = (char *)malloc(size * sizeof(char));
	if (copy == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(copy, s1, size);
	return (copy);
}
