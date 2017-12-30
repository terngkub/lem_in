/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:47:14 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 18:49:18 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_node_pushfront_e(t_node **node, void *content)
{
	if (!ft_node_pushfront(node, content))
		ft_error("failed to create node");
}

void	ft_node_pushback_e(t_node **node, void *content)
{
	if (!ft_node_pushback(node, content))
		ft_error("failed to create node");
}
