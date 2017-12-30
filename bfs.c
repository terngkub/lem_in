/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:56:48 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 18:51:12 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	explore_edge(t_node **queue, t_node *edge, t_room *room)
{
	while (edge)
	{
		if (((t_room *)edge->content)->marked == 0)
		{
			((t_room *)edge->content)->marked = 1;
			((t_room *)edge->content)->edge_to = room;
			ft_node_pushback_e(queue, edge->content);
		}
		edge = edge->next;
	}
}

void	bfs(t_farm *farm)
{
	t_node	*queue;
	t_room	*room;
	t_node	*edge;

	queue = NULL;
	room = farm->start;
	edge = room->edge;
	explore_edge(&queue, edge, room);
	while (queue)
	{
		room = ft_node_pop_front(&queue);
		edge = room->edge;
		explore_edge(&queue, edge, room);
	}
}
