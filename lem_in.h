#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>

typedef struct				s_adjlist_node
{
	int						dst;
	struct s_adjlist_node	*next;
}							t_adjlist_node;

typedef struct				s_adjlist
{
	struct s_adjlist_node	*head;
}							t_adjlist;

typedef struct				s_graph
{
	int						size;
	struct s_adjlist		*array;
}							t_graph;

typedef struct				s_queue
{
	struct s_adjlist_node	*head;
	struct s_adjlist_node	*tail;
}							t_queue;

t_adjlist_node				*create_adjlist_node(int dst);
t_graph						*create_graph(int size);
void						add_edge(t_graph *graph, int src, int dst);
void						print_graph(t_graph *graph);

t_queue						*create_queue(void);
void						push_front(t_queue *queue, int dst);
void						enqueue(t_queue *queue, int dst);
int							dequeue(t_queue *queue);

#endif
