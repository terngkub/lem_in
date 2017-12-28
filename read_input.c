/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:53:57 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 11:57:10 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_isalldigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	read_comment(t_farm *farm, char *str)
{
	char	*next_room;

	if (ft_strcmp(str + 2, "start") == 0)
	{
		get_next_line(0, &next_room);
		read_room(farm, next_room);
		farm->start = farm->room->content;
		free(next_room);
	}
	else if (ft_strcmp(str + 2, "end") == 0)
	{
		get_next_line(0, &next_room);
		read_room(farm, next_room);
		farm->end = farm->room->content;
		free(next_room);
	}
}

void	check_link(char **arr)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (arr[i++])
		len++;
	if (len != 2)
		ft_error();
}

t_room	*find_room(t_farm *farm, char *name)
{
	t_node	*node;

	node = farm->room;
	while (node)
	{
		if (ft_strcmp(((t_room *)node->content)->name, name) == 0)
			return (node->content);
		node = node->next;
	}
	ft_error();
	return (NULL);
}

void	read_link(t_farm *farm, char *str)
{
	char	**arr;
	t_room	*src;
	t_room	*dst;

	if (!(arr = ft_strsplit(str, '-')))
		ft_error();
	check_link(arr);
	src = find_room(farm, arr[0]);
	dst = find_room(farm, arr[1]);
	clear_split(arr);
}

t_room	*create_room(char **arr)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	room->name = ft_strdup(arr[0]);
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);
	room->marked = 0;
	room->edge_to = NULL;
	room->edge = NULL;
	return (room);
}

void	check_room(char **arr)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (arr[i++])
		len++;
	if (len != 3)
		ft_error();
	if (!ft_isalldigit(arr[1]) || !ft_isalldigit(arr[2]))
		ft_error();
}

void	read_room(t_farm *farm, char *str)
{
	char	**arr;
	t_room	*room;

	if (!(arr = ft_strsplit(str, ' ')))
		return ;
	check_room(arr);
	room = create_room(arr);
	ft_node_push_front(&farm->room, ft_node_create(room));
	clear_split(arr);
}

void	read_ant(t_farm *farm)
{
	char	*str;

	get_next_line(0, &str);
	if (!ft_isalldigit(str))
		ft_error();
	farm->ant = ft_atoi(str);
	free(str);
}

void	read_input(t_farm *farm)
{
	t_room	*room;
	char	*str;

	read_ant(farm);
	while (get_next_line(0, &str) > 0)
	{
		if (*str && *(str + 1) && *str == '#' && *(str + 1) == '#')
			read_comment(farm, str);
		else if (ft_strchr(str, '-'))
			read_link(farm, str);
		else
			read_room(farm, str);
		free(str);
	}
}

