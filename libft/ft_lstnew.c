/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:49:32 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/08 14:20:21 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates and returns a new node. The member variable `content` 
// is initialized with the value of the parameter content. 
// The variable `next` is initialized to NULL.

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
	{
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}
