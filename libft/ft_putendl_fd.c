/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:25:58 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/29 09:35:28 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the string s to the given file descriptor followed by a new line.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
