/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:45:33 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 15:19:20 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_push_back(t_node **node, void *content)
{
	t_node	*new;
	t_node	*temp;

	if (!(new = ft_node_create(content)))
		ft_error("failed to create node");
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
