#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				marked;
	struct s_room	*edge_to;
	struct s_node	*edge;
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
	struct s_node	*room;
	struct s_node	*blocked;
}					t_farm;

t_node				*ft_node_create(void *content);
void				ft_node_push_front(t_node **node, t_node *new);
void				ft_node_push_back(t_node **node, t_node *new);
void				*ft_node_pop_front(t_node **node);
void				ft_node_clear(t_node *node, void (*del)(void *));

void				ft_error(void);

void				read_room(t_farm *farm, char *str);
void				read_input(t_farm *farm);

void				clear_split(char **arr);
void				clear_link(void *content, size_t content_size);
void				clear_room(void *content, size_t content_size);

void				print_graph(t_farm *farm);
void				create_graph(t_farm *farm);

t_node				*get_path(t_farm *farm);
void				bfs(t_farm *farm);
void				set_room(t_farm *farm);
void				get_all_paths(t_farm *farm);

void				print_path(t_node *node);

#endif
