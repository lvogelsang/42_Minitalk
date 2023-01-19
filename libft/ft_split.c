/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:51:13 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/12 12:37:59 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns an array of strings obtained by splitting s using the character c
// as a delimiter. The array must end with a NULL pointer.

#include "libft.h"

int	ft_sep(char const *s, int index, char c)
{
	if (s[index] == c)
	{
		if ((s[index + 1]) != c && (s[index + 1]) != '\0')
		{
			return (1);
		}
	}
	return (0);
}

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (ft_strlen(s) == 0)
	{
		return (0);
	}
	if (s[i] != c)
	{
		count++;
	}
	while (s[i])
	{
		if (ft_sep(s, i, c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_createword(char **split, int j, char const *s, char c)
{
	int		x;

	x = 0;
	while (s[x] != c && s[x] != '\0')
	{
		x++;
	}
	split[j] = (char *)malloc((x + 1) * sizeof(char));
	if (split[j] == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(split[j], s, x + 1);
	return (split[j]);
}

void	ft_createarr(char **split, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] != c && s[i] != '\0')
	{
		ft_createword(split, j, (s + i), c);
		j++;
	}
	while (s[i])
	{
		if (ft_sep(s, i, c))
		{
			ft_createword(split, j, (s + i + 1), c);
			j++;
		}
		i++;
	}
	split[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**split;

	count = 0;
	if (!(*s))
	{
		split = (char **)malloc(sizeof(char *));
	}
	else
	{
		count = ft_wordcount(s, c);
		split = (char **)malloc((count + 1) * sizeof(char *));
	}
	if (split == NULL)
	{
		return (NULL);
	}
	ft_createarr(split, s, c);
	return (split);
}
