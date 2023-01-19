/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:38:55 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/29 14:24:37 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function f to each character of the string s, and passing its
// index as first argument to create a new string resulting from successive
// applications of f.

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	char			*s_new;
	unsigned int	i;

	len = ft_strlen(s);
	s_new = (char *)malloc((len + 1) * sizeof(char));
	if (s_new == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		s_new[i] = f(i, s[i]);
		i++;
	}
	s_new[i] = '\0';
	return (s_new);
}
