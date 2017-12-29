/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:46:24 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 18:46:45 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
