/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:46:54 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 18:47:18 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_delete(t_node *node, void (*del)(void *))
{
	t_node	*temp;

	while (node)
	{
		temp = node;
		if (del)
			del(node->content);
		node = node->next;
		free(temp);
	}
}
