/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:20:40 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 19:49:24 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	struct s_node	*edge;
}					t_room;

typedef struct		s_ant
{
	size_t			nbr;
	struct s_node	*path;
	size_t			ant_color;
	size_t			path_color;
}					t_ant;

typedef struct		s_farm
{
	char			*input;
	size_t			ant_num;
	struct s_room	*start;
	struct s_room	*end;
	struct s_node	*room;
	struct s_node	*blocked;
	struct s_node	*all_path;
	size_t			path_num;
	struct s_node	*ant;
	size_t			*alloc;
}					t_farm;

void				farm_init(t_farm *farm);

int					ft_isalldigit(char *str);
void				print_path(t_node *node);
void				print_all_path(t_farm *farm);
void				print_allocation(t_farm *farm);

void				read_comment(t_farm *farm, char *str);
void				read_ant(t_farm *farm);
void				read_input(t_farm *farm);

t_room				*create_room(char **arr);
void				check_room(t_farm *farm, char **arr);
void				read_room(t_farm *farm, char *str);

void				check_link(char **arr);
void				read_link(t_farm *farm, char *stra);
t_room				*find_room(t_farm *farm, char *name);

void				add_blocked(t_farm *farm, t_node *path);
t_node				*get_path(t_farm *farm);
void				set_room(t_farm *farm);
void				get_all_path(t_farm *farm);

void				explore_edge(t_node **queue, t_node *edge, t_room *room);
void				bfs(t_farm *farm);

void				array_increment(size_t *arr, size_t len, size_t increment);
size_t				array_sum(size_t *arr, size_t len);
void				compute_lag(t_farm *farm);
void				allocate_ant(t_farm *farm);

void				create_ant(t_farm *farm, size_t *nbr);
void				move_ant(t_farm *farm);

void				delete_split(char **arr);
void				delete_path(void *node);
void				delete_room(void *node);
void				delete_ant(void *node);
void				clean_all(t_farm *farm);

void				ft_error(char *str);
void				*ft_malloc_e(size_t size);
char				*ft_strdup_e(char *str);
char				**ft_strsplit_e(char *str, char c);
char				*ft_strfreecat_back_e(char **str1, char *str2);

void				ft_node_pushfront_e(t_node **node, void *content);
void				ft_node_pushback_e(t_node **node, void *content);

#endif
