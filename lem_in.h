#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				marked;
	struct s_room	*edge_to;
	struct s_stack	*edge;
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
	struct s_stack	*blocked;
}					t_farm;

void				ft_error(void);

t_room				*create_room(void);
void				read_room(t_farm *farm, char *str);
void				read_input(t_farm *farm);

void				clear_split(char **arr);
void				clear_link(void *content, size_t content_size);
void				clear_room(void *content, size_t content_size);

void				print_graph(t_farm *farm);
void				create_graph(t_farm *farm);

t_queue				*get_path(t_farm *farm);
void				bfs(t_farm *farm);
void				set_room(t_farm *farm);

#endif
