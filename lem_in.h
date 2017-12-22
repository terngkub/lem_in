#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct		s_node
{
	int				n;
	struct s_node	*next;
}					t_node;

t_node				*create_node(int n);

typedef struct		s_stack
{
	int				size;
	struct s_node	*head;
}					t_stack;

t_stack				*create_stack(void);
void				push(t_stack *stack, int n);
int					pop(t_stack *stack);
void				print_stack(t_stack *stack);

typedef struct			s_stack_node
{
	struct s_stack		*stack;
	struct s_stack_list	*next;
}						t_stack_node;

t_stack_node			*create_stack_node(t_stack *stack);

typedef struct			s_stack_list
{
	int					size;
	struct s_stack_node	*head;
}						t_stack_list;

t_stack_list			create_stack_list(void);
void					push_stack(t_stack_node *stack_node);

typedef struct		s_queue
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}					t_queue;

t_queue				*create_queue(void);
void				enqueue(t_queue *queue, int n);
int					dequeue(t_queue *queue);
void				print_queue(t_queue *queue);

typedef struct		s_graph
{
	int				size;
	struct s_stack	**array;
}					t_graph;

t_graph				*create_graph(int size);
void				add_edge(t_graph *graph, int src, int dst);
void				print_graph(t_graph *graph);

#endif
