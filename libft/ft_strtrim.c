/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:04:18 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/08 11:05:42 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a copy of s1 with the characters specified in set removed from the
// beginning and the end of the string.

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*trim;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (s1[j] && ft_strrchr(set, s1[j]))
		j--;
	if (j < i)
	{
		trim = (char *)malloc(sizeof(char));
		ft_bzero(trim, 1);
	}
	else
		trim = (char *)malloc((j - i + 2) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, s1 + i, j - i + 2);
	return (trim);
}
