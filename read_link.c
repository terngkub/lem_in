/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:35:00 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 15:38:13 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	t_room	*room1;
	t_room	*room2;

	if (!(arr = ft_strsplit(str, '-')))
		ft_error();
	check_link(arr);
	room1 = find_room(farm, arr[0]);
	room2 = find_room(farm, arr[1]);
	ft_node_push_front(&room1->edge, ft_node_create(room2));
	ft_node_push_front(&room2->edge, ft_node_create(room1));
	delete_split(arr);
}
