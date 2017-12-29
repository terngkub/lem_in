/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:45:33 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 18:45:59 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
