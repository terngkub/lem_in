/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:04:33 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/22 18:05:14 by nkamolba         ###   ########.fr       */
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

void			shortest_path(t_graph *graph, int src, int dst)
{
	t_queue			*queue;
	t_adjlist_node	*node;
	int				marked[graph->size];
	int				edge_to[graph->size];
	int				v;
	int				i;
	t_queue			*path;

	queue = create_queue();
	node = graph->array[src].head;
	i = 0;
	while (i < graph->size)
	{
		marked[i] = 0;
		edge_to[i++] = -1;
	}
	marked[0] = 1;
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
	path = get_path(edge_to, src, dst);
	i = 0;
	while (i < graph->size)
	{
		printf("%d: %d\n", i, edge_to[i]);
		i++;
	}
	node = path->head;
	while(node)
	{
		printf("%d ", node->dst);
		node = node->next;
	}
}

int				main(void)
{
	t_graph			*graph;

	graph = create_graph(8);
	add_edge(graph, 0, 1);
	add_edge(graph, 0, 2);
	add_edge(graph, 1, 6);
	add_edge(graph, 2, 3);
	add_edge(graph, 2, 4);
	add_edge(graph, 3, 6);
	add_edge(graph, 4, 5);
	add_edge(graph, 5, 6);
	add_edge(graph, 5, 7);
	add_edge(graph, 6, 7);
	print_graph(graph);
	shortest_path(graph, 0, 7);
	return (0);
}
