/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:34:06 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 16:38:09 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_room(char **arr)
{
	t_room	*room;

	room = (t_room *)ft_malloc_e(sizeof(t_room));
	room->name = ft_strdup_e(arr[0]);
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);
	room->marked = 0;
	room->edge_to = NULL;
	room->edge = NULL;
	return (room);
}

void	check_room(t_farm *farm, char **arr)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (arr[i++])
		len++;
	if (len != 3)
		ft_error("room input arguments aren't 3");
	if (find_room(farm, arr[0]))
		ft_error("duplicated room name");
	if (!ft_isalldigit(arr[1]) || !ft_isalldigit(arr[2]))
		ft_error("x or y aren't number");
}

void	read_room(t_farm *farm, char *str)
{
	char	**arr;
	t_room	*room;

	if (*str == 'L')
		ft_error("room can't start with letter L");
	arr = ft_strsplit_e(str, ' ');
	check_room(farm, arr);
	room = create_room(arr);
	ft_node_push_front(&farm->room, ft_node_create(room));
	delete_split(arr);
	farm->input = ft_strfreecat_back(&farm->input, str);
	farm->input = ft_strfreecat_back(&farm->input, "\n");
}
