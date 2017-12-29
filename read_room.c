/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:34:06 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 19:56:35 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (ft_strlen(arr[0]) == 0 || ft_strlen(arr[1]) == 0 ||
			ft_strlen(arr[2]) == 0)
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
	delete_split(arr);
	farm->input = ft_strfreecat_back(&farm->input, str);
	farm->input = ft_strfreecat_back(&farm->input, "\n");
}
