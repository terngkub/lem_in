/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:55:31 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 15:50:19 by nkamolba         ###   ########.fr       */
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
			break ;
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

void	get_all_path(t_farm *farm)
{
	t_node	*path;

	if (!farm->start || !farm->end) 
		ft_error("no start or end room");
	if (farm->start == farm->end)
		ft_error("start and end rooms are the same");
	while (1)
	{
		set_room(farm);
		bfs(farm);
		if (!(path = get_path(farm)))
			break ;
		ft_node_push_back(&farm->all_path, ft_node_create(path));
		farm->path_num += 1;
		ft_node_push_front(&farm->blocked, ft_node_create(path->content));
		add_blocked(farm, path);
	}
	if (!farm->all_path)
		ft_error("no available path");
}
