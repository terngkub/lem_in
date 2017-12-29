/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:38:09 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 18:44:45 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_node_create(void *content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->content = content;
	node->next = NULL;
	return (node);
}
