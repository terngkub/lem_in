/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:32:04 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 15:34:51 by nkamolba         ###   ########.fr       */
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

	if (!(*node))
		*node = new;
	else
	{
		temp = *node;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	*ft_node_pop_front(t_node **node)
{
	void	*content;
	t_node	*temp;

	if (!(*node))
		return (NULL);
	temp = *node;
	content = temp->content;
	*node = temp->next;
	free(temp);
	return (content);
}

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
