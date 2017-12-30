/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:35:00 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 15:46:04 by nkamolba         ###   ########.fr       */
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
	return (NULL);
}

void	check_link(char **arr) {
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (arr[i++])
		len++;
	if (len != 2)
		ft_error("link input isn't valid");
}

void	read_link(t_farm *farm, char *str)
{
	char	**arr;
	t_room	*room1;
	t_room	*room2;

	arr = ft_strsplit_e(str, '-');
	check_link(arr);
	if (!(room1 = find_room(farm, arr[0])))
		ft_error("couldn't find room");
	if (!(room2 = find_room(farm, arr[1])))
		ft_error("couldn't find room");
	ft_node_push_front(&room1->edge, ft_node_create(room2));
	ft_node_push_front(&room2->edge, ft_node_create(room1));
	delete_split(arr);
	farm->input = ft_strfreecat_back(&farm->input, str);
	farm->input = ft_strfreecat_back(&farm->input, "\n");
}
