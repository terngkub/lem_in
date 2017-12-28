/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:35:55 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 18:12:13 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	ft_node_len(t_node *node)
{
	size_t	len;

	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

size_t	*create_lag_array(t_node *all_path)
{
	size_t	len;
	size_t	*arr;
	size_t	i;
	size_t	lowest;

	len = ft_node_len(all_path);
	if (!(arr = (size_t *)malloc(sizeof(size_t) * len)))
		ft_error();
	i = 0;
	while (i < len)
	{
		arr[i++] = ft_node_len(all_path->content);
		all_path = all_path->next;
	}
	lowest = arr[0];
	i = 0;
	while (i < len)
		arr[i++] -= lowest;
	return (arr);
}

void	create_ant(t_node *all_path, size_t *lag_array, t_node *ant, size_t i)
{
	size_t	len;
	size_t	path_nbr;
	t_ant	*ant;

	len = ft_node_len(all_path);
	path_nbr = (i % len) - 1;
	if (!(ant = (t_ant *)malloc(sizeof(t_ant))))
		ft_error();
	ant->ant_nbr = i;
	while (i < path_nbr)

	



}

/*
void	move_ant(t_farm *farm, t_node *all_path)
{
	t_node	*ant;

	i = 0;
	while (1)
	{
		if (i < farm->ant)
			create_ant(ant, i);
		finish = 1;
		while (ant)
		{
			if (((t_room *)ant->path->content) != farm->end)
			{
				//path = path->next;
				//print ant
				//print room
			}
			else
				finish = 0;
		}
		if (finish == 1)
			break;
		i++;
	}
}
*/
