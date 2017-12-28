/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:55:31 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 15:55:08 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_blocked(t_farm *farm, t_node *path)
{
	while (path)
	{
		if (path->content != farm->end)
			ft_node_push_front(&farm->blocked, ft_node_create(path->content));
		path = path->next;
	}
}

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
	ft_node_delete(path, NULL);
	return (NULL);
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

t_node	*get_all_paths(t_farm *farm)
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
		add_blocked(farm, path);
		print_path(path);
	}
	return (all_paths);
}
