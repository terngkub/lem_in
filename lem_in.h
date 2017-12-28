/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:20:40 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 16:20:41 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void				ft_node_delete(t_node *node, void (*del)(void *));

void				ft_error(void);
int					ft_isalldigit(char *str);
void				print_path(t_node *node);

void				read_comment(t_farm *farm, char *str);
void				read_ant(t_farm *farm);
void				read_input(t_farm *farm);
void				print_graph(t_farm *farm);

t_room				*create_room(char **arr);
void				check_room(char **arr);
void				read_room(t_farm *farm, char *str);

void				check_link(char **arr);
void				read_link(t_farm *farm, char *stra);
t_room				*find_room(t_farm *farm, char *name);

void				add_blocked(t_farm *farm, t_node *path);
t_node				*get_path(t_farm *farm);
void				set_room(t_farm *farm);
t_node				*get_all_paths(t_farm *farm);

void				explore_edge(t_node **queue, t_node *edge, t_room *room);
void				bfs(t_farm *farm);

void				delete_split(char **arr);
void				delete_path(void *node);
void				delete_room(void *node);
void				clean_all(t_farm *farm, t_node *all_paths);

#endif
