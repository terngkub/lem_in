/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:34:59 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 17:44:31 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_split(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	delete_path(void *node)
{
	t_node	*path;

	path = node;
	ft_node_delete(path, NULL);
}

void	delete_room(void *node)
{
	t_room *room;

	room = node;
	free(room->name);
	ft_node_delete(room->edge, NULL);
	free(room);
}

void	delete_ant(void *node)
{
	free(node);
}

void	clean_all(t_farm *farm)
{
	ft_node_delete(farm->room, delete_room);
	ft_node_delete(farm->blocked, NULL);
	ft_node_delete(farm->all_path, delete_path);
	ft_node_delete(farm->ant, delete_ant);
	free(farm->alloc);
}
