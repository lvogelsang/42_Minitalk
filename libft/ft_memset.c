/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:04:13 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/29 14:48:45 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memset() function writes len bytes of value c 
// (converted to an unsigned char) to the string b.

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (len)
	{
		((unsigned char *)b)[i] = c;
		len--;
		i++;
	}
	return (b);
}
