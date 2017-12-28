/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:32:04 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 11:32:45 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*ft_node_create(void *content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_node_push_front(t_node **node, t_node *new)
{
	new->next = *node;
	*node = new;
}

void	ft_node_push_back(t_node **node, t_node *new)
{
	t_node	*temp;

	temp = *node;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_node_clear(t_node *node, void (*del)(void *))
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
