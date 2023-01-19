/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:13:56 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/09 13:24:31 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Adds the node new at the end of the list.

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
	{
		*lst = new;
	}
	else
	{
		last->next = new;
	}
}
