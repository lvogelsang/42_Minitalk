/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:46:42 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/14 10:49:05 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the character c to the given file descriptor.

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
