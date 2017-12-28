/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:34:59 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 16:20:23 by nkamolba         ###   ########.fr       */
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

	path = (t_node *)node;
	ft_node_delete(path, NULL);
}

void	delete_room(void *node)
{
	t_room *room;

	room = (t_room *)node;
	free(room->name);
	ft_node_delete(room->edge, NULL);
	free(room);
}

void	clean_all(t_farm *farm, t_node *all_paths)
{
	ft_node_delete(farm->room, delete_room);
	ft_node_delete(farm->blocked, NULL);
	ft_node_delete(all_paths, delete_path);
}
