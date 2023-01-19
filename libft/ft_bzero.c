/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:51:17 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/26 12:00:33 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The bzero() function writes n zeroed bytes to the string s.
//If n is zero, bzero() does nothing.

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
