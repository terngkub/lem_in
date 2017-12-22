/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 19:14:05 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/22 19:14:19 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node			*create_node(int n)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		exit(1);
	node->n = n;
	node->next = NULL;
	return (node);
}
