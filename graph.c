/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:02:55 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/22 23:26:54 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


t_graph	*create_graph(int size)
{
	t_graph	*graph;
	int		i;

	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		exit(1);
	if (!(graph->array = (t_stack **)malloc(sizeof(t_stack *) * size)))
		exit(1);
	graph->size = size;
	i = 0;
	while (i < size)
		graph->array[i++] = create_stack();
	return (graph);
}

void	add_edge(t_graph *graph, int src, int dst)
{
	push(graph->array[dst], src);
	push(graph->array[src], dst);
}

void	print_graph(t_graph *graph)
{
	int		i;
	t_node	*node;
	
	i = 0;
	while (i < graph->size)
	{
		node = graph->array[i]->head;
		ft_printf("head %d ", i);
		while (node)
		{
			ft_printf("-> %d ", node->n);
			node = node->next;
		}
		ft_printf("\n"); i++;
	}
}
