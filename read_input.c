/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:53:57 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/27 13:31:10 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(1);
}

void	read_comment(t_farm *farm, char *str)
{
	char	*next_room;

	if (ft_strcmp(str + 2, "start") == 0)
	{
		get_next_line(0, &next_room);
		read_room(farm, next_room);
		farm->start = farm->room->head->content;
		free(next_room);
	}
	else if (ft_strcmp(str + 2, "end") == 0)
	{
		get_next_line(0, &next_room);
		read_room(farm, next_room);
		farm->end = farm->room->head->content;
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

void	read_link(t_farm *farm, char *str)
{
	char	**arr;
	t_link	*link;

	if (!(arr = ft_strsplit(str, '-')))
		ft_error();
	check_link(arr);
	if (!(link = (t_link *)malloc(sizeof(t_link))))
		ft_error();
	link->src = ft_strdup(arr[0]);
	link->dst = ft_strdup(arr[1]);
	ft_stack_push(farm->link, link);
	clear_split(arr);
	free(link);
}

t_room	*create_room(void)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	room->name = NULL;
	room->x = 0;
	room->y = 0;
	room->edge = ft_stack_create(sizeof(t_room *));
	return (room);
}

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
	room = create_room();
	room->name = ft_strdup(arr[0]);
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);
	ft_stack_push(farm->room, room);
	clear_split(arr);
	free(room);
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
