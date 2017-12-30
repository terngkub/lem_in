/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:45:33 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 18:46:54 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_node_pushback(t_node **node, void *content)
{
	t_node	*new;
	t_node	*temp;

	if (!(new = ft_node_create(content)))
		return (0);
	if (!(*node))
		*node = new;
	else
	{
		temp = *node;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}
