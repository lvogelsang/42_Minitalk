/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:42:38 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/16 13:42:22 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_FD	4096

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

char	*get_next_line(int fd);
char	*gnl_read_save_line(int fd, char **buf);
char	*gnl_format_line(int fd, char **buf);
char	*gnl_next_next_line(int fd, char **buf);

char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *buf, char *temp);
void	gnl_strjoin_2(char *concat, char *buf, char *temp);
size_t	gnl_strlen(const char *s);

#endif
