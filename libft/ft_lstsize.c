/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:53:24 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/09 12:31:40 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Counts the number of nodes in a list.

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	if (lst)
	{
		len = 1;
		while (lst->next)
		{
			len++;
			lst = lst->next;
		}
	}
	return (len);
}
