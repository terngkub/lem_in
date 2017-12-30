/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:44:52 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 15:19:58 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_push_front(t_node **node, void *content)
{
	t_node	*new;

	if (!(new = ft_node_create(content)))
		ft_error("failed to create node");
	new->next = *node;
	*node = new;
}
