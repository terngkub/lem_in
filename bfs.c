/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:04:33 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/22 23:43:15 by terng            ###   ########.fr       */
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

t_stack	**get_all_paths(t_graph *graph)
{

}

int				main(void)
{
	t_graph			*graph;
	int				*edge_to;
	t_queue			*path;

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
	edge_to = bfs(graph, 0);
	path = get_path(edge_to, 0, 7);
	print_queue(path);
	return (0);
}
