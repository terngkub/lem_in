/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:04:33 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/27 13:59:49 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue			*get_path(int *edge_to, int src, int dst)
{
	t_queue			*path;
	int				current;

	path = create_queue();
	push_front(path, dst);
	current = edge_to[dst];
	while (current != src)
	{
		push_front(path, current);
		current = edge_to[current];
	}
	return (path);
}

int				*create_marked(t_queue *queue, int src, int size)
{
	int				*marked;
	t_adjlist_node	*node;

	if (!(marked = ft_memealloc(sizeof(int) * size)))
		exit(1);
	marked[src] = 1;
	node = queue->head;
	while (node)
	{
		marked[node->dst] = 1;
		node = node->next;
	}
	return (marked);
}

int				*bfs(t_graph *graph, int src)
{
	t_queue	*queue;
	t_node	*node;
	int		*marked;
	int		*edge_to;
	int		v;
	int		i;

	queue = create_queue();
	if (!(edge_to = ft_memalloc(sizeof(int) * graph->size)))
		exit(1);
	marked = create_marked;
	node = graph->array[src].head;
	while (node)
	{
		marked[node->dst] = 1;
		edge_to[node->dst] = src;
		enqueue(queue, node->dst);
		node = node->next;
	}
	while (queue->head)
	{
		v = dequeue(queue);
		node = graph->array[v].head;
		while (node)
		{
			if (marked[node->dst] == 0)
			{
				marked[node->dst] = 1;
				edge_to[node->dst] = v;
				enqueue(queue, node->dst);
			}
			node = node->next;
		}
	}
	return (edge_to);
}

int		*bfs(t_farm *farm)
{
}
