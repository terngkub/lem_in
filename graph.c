#include "lem_in.h"

t_adjlist_node	*create_adjlist_node(int dst)
{
	t_adjlist_node	*node;

	if (!(node = (t_adjlist_node *)malloc(sizeof(t_adjlist_node))))
		return (0);
	node->dst = dst;
	node->next = NULL;
	return (node);
}

t_graph			*create_graph(int size)
{
	t_graph			*graph;
	int				i;

	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		return (0);
	if (!(graph->array = (t_adjlist *)malloc(sizeof(t_adjlist) * size)))
		return (0);
	graph->size = size;
	i = 0;
	while (i < size)
		graph->array[i++].head = NULL;
	return (graph);
}

void			add_edge(t_graph *graph, int src, int dst)
{
	t_adjlist_node	*node;

	node = create_adjlist_node(src);
	node->next = graph->array[dst].head;
	graph->array[dst].head = node;
	node = create_adjlist_node(dst);
	node->next = graph->array[src].head;
	graph->array[src].head = node;
}

void			print_graph(t_graph *graph)
{
	int				i;
	t_adjlist_node	*node;
	
	i = 0;
	while (i < graph->size)
	{
		node = graph->array[i].head;
		printf("head %d ", i);
		while (node)
		{
			printf("-> %d ", node->dst);
			node = node->next;
		}
		printf("\n");
		i++;
	}
}

t_queue			create_queue(void)
{
	t_queue			*queueu;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		reutrn (0);
	queue->head = NULL;
	queue->tail = NULL;
	return (queue);
}

void			enqueue(t_queue *queue, int dst)
{
	t_adjlist_node	*node;

	if (!queue)
		return (NULL);
	node = create_adjlist_node(dst);
	if (queue->head == NULL)
	{
		queue->head = node;
		queue->tail = node;
	}
	else
	{
		queue->tail->next = node;
		queue->tail = node;
	}
}

int				dequeue(t_queue *queue)
{
	t_adjlist_node	*node;

	if (!queue || !(queue->head))
		return (NULL);

}

void			*shortest_path(t_graph *graph, int src, int dst)
{
	int				marked[graph->size];
	int				edge_to[graph->size];

	//queue
	marked[src] = 1;
	//enqueue
	//while (queue is not empty)
	//	v = dequeue
	//	node
	//	while graph->array[v].head
	//			edge_to[

}

int				main(void)
{
	t_graph			*graph;

	graph = create_graph(4);
	add_edge(graph, 0, 1);
	add_edge(graph, 0, 2);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 2, 3);
	print_graph(graph);
	return (0);
}
