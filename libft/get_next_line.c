/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:42:57 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/18 09:49:28 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// The get_next_line function lets you read the text file pointed to by the 
// file descriptor, one line at a time.

// This is done in three steps: First, we read from the file (until
// we encounter a new line character) and save what was read. Second, we
// store everything before and including the new line character in a new 
// variable (this is the return value). Third, we remove the part of the line 
// that is returned from our reading buffer, so that only characters after the 
// new line character remain. We store it in our static array, which is then 
// ready for the next function call.

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buf[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE < 0)
		return (NULL);
	buf[fd] = gnl_read_save_line(fd, buf);
	if (buf[fd] == NULL)
		return (NULL);
	next_line = gnl_format_line(fd, buf);
	buf[fd] = gnl_next_next_line(fd, buf);
	return (next_line);
}

char	*gnl_read_save_line(int fd, char **buf)
{
	char	*temp;
	int		nbytes;

	temp = (char *)malloc((BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	nbytes = 1;
	while ((!(gnl_strchr(buf[fd], '\n'))) && nbytes)
	{
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (temp);
			free (buf[fd]);
			return (NULL);
		}
		temp[nbytes] = '\0';
		buf[fd] = gnl_strjoin(buf[fd], temp);
	}
	free (temp);
	return (buf[fd]);
}

char	*gnl_format_line(int fd, char **buf)
{
	char	*next_line;
	int		i;

	i = 0;
	if (buf[fd][i] == '\0')
		return (NULL);
	while (buf[fd][i] && buf[fd][i] != '\n')
		i++;
	next_line = (char *)malloc((i + 2) * sizeof(char));
	if (next_line == NULL)
		return (NULL);
	i = 0;
	while (buf[fd][i] && buf[fd][i] != '\n')
	{
		next_line[i] = buf[fd][i];
		i++;
	}
	if (buf[fd][i] == '\n')
	{
		next_line[i] = '\n';
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*gnl_next_next_line(int fd, char **buf)
{
	char	*next_next_line;
	int		i;
	int		j;

	i = 0;
	while (buf[fd][i] && buf[fd][i] != '\n')
		i++;
	if (buf[fd][i] == '\0')
	{
		free (buf[fd]);
		return (NULL);
	}
	i++;
	next_next_line = (char *)malloc(gnl_strlen(buf[fd]) - i + 1);
	if (next_next_line == NULL)
		return (NULL);
	j = 0;
	while (buf[fd][i + j])
	{
		next_next_line[j] = buf[fd][i + j];
		j++;
	}
	next_next_line[j] = '\0';
	free (buf[fd]);
	return (next_next_line);
}
