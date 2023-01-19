/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:43:18 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/16 13:49:02 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// These are helper functions for get_next_line, which were taken from the libft
// library but have been partially modified.

// STRCHR is used to determine whether we have encountered a new line character
// after reading from the text file.

char	*gnl_strchr(const char *s, int c)
{
	c = c % 256;
	if (s == NULL)
		return (NULL);
	if (*s == c)
		return ((char *)s);
	s++;
	while (*(s - 1))
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// STRJOIN is used to add "temp" (which includes the read bytes) to our
// buffer. The reading and joining process is repeated until STRCHR finds a
// new line character.

char	*gnl_strjoin(char *buf, char *temp)
{
	char	*concat;
	size_t	len;

	if (buf == NULL)
	{
		buf = (char *)malloc(sizeof(char));
		if (buf == NULL)
			return (NULL);
		buf[0] = '\0';
	}
	if (temp == NULL)
		return (NULL);
	len = gnl_strlen(buf) + gnl_strlen(temp);
	concat = (char *)malloc((len + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);
	gnl_strjoin_2(concat, buf, temp);
	return (concat);
}

void	gnl_strjoin_2(char *concat, char *buf, char *temp)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buf[i] != '\0')
	{
		concat[i] = buf[i];
		i++;
	}
	j = 0;
	while (temp[j] != '\0')
	{
		concat[i + j] = temp[j];
		j++;
	}
	concat[i + j] = '\0';
	free (buf);
}

// STRLEN is used to calculate string lenghts throughout the program.

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
