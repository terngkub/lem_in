/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:04:33 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/27 17:07:58 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*get_path(t_farm *farm)
{
	t_queue	*path;
	t_room	*room;

	path = ft_queue_create(sizeof(room));
	room = farm->end;
	while (room)
	{
		ft_queue_enqueue(path, room);
		room = room->edge_to;
		if (room == farm->start)
		{
			ft_printf("end\n");
			break;
		}
	}
	return (path);
}

void	bfs(t_farm *farm)
{
	t_queue	*queue;
	t_room	*room;
	t_list	*edge;

	queue = ft_queue_create(sizeof(t_room));
	room = farm->start;
	room->marked = 1;
	edge = room->edge->head;
	while (edge)
	{
		((t_room *)edge->content)->marked = 1;
		((t_room *)edge->content)->edge_to = room;
		ft_queue_enqueue(queue, edge->content);
		edge = edge->next;
	}
	while (queue->head)
	{
		room = ft_queue_dequeue(queue);
		edge = room->edge->head;
		ft_printf("test\n");
		while (edge)
		{
			ft_printf("%d\n", ((t_room *)edge->content)->marked);
			if (((t_room *)edge->content)->marked == 0)
			{
				ft_queue_enqueue(queue, edge->content);
				((t_room *)edge->content)->marked = 1;
				((t_room *)edge->content)->edge_to = room;
				ft_printf("%s %s\n", ((t_room *)edge->content)->name, ((t_room *)edge->content)->edge_to->name);
			}
			edge = edge->next;
		}
	}
}

void	set_room(t_farm *farm)
{
	t_list	*current;

	current = farm->room->head;
	while (current)
	{
		((t_room *)current->content)->marked = 0;
		((t_room *)current->content)->edge_to = NULL;
		current = current->next;
	}
	current = farm->blocked->head;
	while (current)
	{
		((t_room *)current->content)->marked = 1;
		current = current->next;
	}
}

/*
t_queue	*get_all_paths(t_farm *farm)
{
	t_queue	*all_paths;
	t_queue	*path;

	all_paths = ft_queue_create(sizeof(t_queue));
	while (1)
	{
		set_room(farm);
		if (!(path = bfs(farm)))
			break;
		ft_queue_enqueue(all_paths, path);
	}
	return (all_paths);
}
*/
