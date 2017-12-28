/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:04:33 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 14:03:02 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*get_path(t_farm *farm)
{
	t_node	*path;
	t_room	*room;

	path = NULL;
	room = farm->end;
	while (room)
	{
		ft_node_push_front(&path, ft_node_create(room));
		room = room->edge_to;
		if (room == farm->start)
			break;
	}
	if (room == farm->start)
		return (path);
	else
		return (NULL);
}

void	bfs(t_farm *farm)
{
	t_node	*queue;
	t_room	*room;
	t_node	*edge;

	queue = NULL;
	room = farm->start;
	edge = room->edge;
	while (edge)
	{
		if (((t_room *)edge->content)->marked == 0)
		{
			((t_room *)edge->content)->marked = 1;
			((t_room *)edge->content)->edge_to = room;
			ft_node_push_back(&queue, ft_node_create(edge->content));
		}
		edge = edge->next;
	}
	while (queue)
	{
		room = ft_node_pop_front(&queue);
		edge = room->edge;
		while (edge)
		{
			if (((t_room *)edge->content)->marked == 0)
			{
				((t_room *)edge->content)->marked = 1;
				((t_room *)edge->content)->edge_to = room;
				ft_node_push_back(&queue, ft_node_create(edge->content));
			}
			edge = edge->next;
		}
	}
}

void	set_room(t_farm *farm)
{
	t_node	*node;

	node = farm->room;
	while (node)
	{
		((t_room *)node->content)->marked = 0;
		((t_room *)node->content)->edge_to = NULL;
		node = node->next;
	}
	node = farm->blocked;
	while (node)
	{
		((t_room *)node->content)->marked = 1;
		node = node->next;
	}
	farm->start->marked = 1;
}

void	get_all_paths(t_farm *farm)
{
	t_node	*all_paths;
	t_node	*path;

	all_paths = NULL;
	while (1)
	{
		set_room(farm);
		bfs(farm);
		if (!(path = get_path(farm)))
			break;
		ft_node_push_back(&all_paths, ft_node_create(path));
		ft_node_push_front(&farm->blocked, ft_node_create(path->content));
		print_path(path);
	}
}
