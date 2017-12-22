/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:02:55 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/22 19:40:07 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


t_graph	*create_graph(int size)
{
	t_graph	*graph;
	int		i;

	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		exit(1);
	if (!(graph->array = (t_stack *)malloc(sizeof(t_stack) * size)))
		exit(1);
	graph->size = size;
	i = 0;
	while (i < size)
		graph->array[i++].head = NULL;
	return (graph);
}

void	add_edge(t_graph *graph, int src, int dst)
{
	t_node	*node;

	node = create_node(src);
	node->next = graph->array[dst].head;
	graph->array[dst].head = node;
	node = create_node(dst);
	node->next = graph->array[src].head;
	graph->array[src].head = node;
}

void	print_graph(t_graph *graph)
{
	int		i;
	t_node	*node;
	
	i = 0;
	while (i < graph->size)
	{
		node = graph->array[i].head;
		printf("head %d ", i);
		while (node)
		{
			printf("-> %d ", node->n);
			node = node->next;
		}
		printf("\n");
		i++;
	}
}
