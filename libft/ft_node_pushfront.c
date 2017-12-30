/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_pushfront.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:44:52 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 18:46:34 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_node_pushfront(t_node **node, void *content)
{
	t_node	*new;

	if (!(new = ft_node_create(content)))
		return (0);
	new->next = *node;
	*node = new;
	return (1);
}
