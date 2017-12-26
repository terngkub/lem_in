#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	t_stack			*edge;
}					t_room;

typedef struct		s_link
{
	char			*src;
	char			*dst;
}					t_link;

typedef struct		s_farm
{
	size_t			ant;
	struct s_room	*start;
	struct s_room	*end;
	struct s_stack	*room;
	struct s_stack	*link;
}					t_farm;

t_room				*create_room(void);
void				read_room(t_farm *farm, char *str);
void				read_input(t_farm *farm);

void				clear_split(char **arr);
void				clear_link(void *content, size_t content_size);
void				clear_room(void *content, size_t content_size);


/*
typedef struct		s_graph
{
	int				size;
	struct s_stack	**array;
}					t_graph;

t_graph				*create_graph(int size);
void				add_edge(t_graph *graph, int src, int dst);
void				print_graph(t_graph *graph);
*/

#endif