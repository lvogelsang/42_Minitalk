/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:35:20 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/12 11:19:08 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The calloc() function contiguously allocates enough space for count
// objects that are size bytes of memory each and returns a pointer to the
// allocated memory. The allocated memory is filled with bytes of value
// zero.

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memzero;
	size_t	total_size;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	total_size = count * size;
	memzero = (void *)malloc(total_size);
	if (memzero == NULL)
	{
		return (NULL);
	}
	ft_bzero(memzero, total_size);
	return (memzero);
}
