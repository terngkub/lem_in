/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:35:55 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 17:45:40 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_ant(t_farm *farm, size_t *nbr)
{
	size_t	i;
	size_t	j;
	t_node	*path;
	t_ant	*ant;

	i = 0;
	while (i < farm->path_num && *nbr <= farm->ant_num)
	{
		if (farm->alloc[i] > 0)
		{
			if (!(ant = (t_ant *)malloc(sizeof(t_ant))))
				ft_error();
			ant->nbr = *nbr;
			path = farm->all_path;
			j = 0;
			while (j++ < i)
				path = path->next;
			ant->path = path->content;
			farm->alloc[i]--;
			*nbr += 1;
			ft_node_push_back(&farm->ant, ft_node_create(ant));
		}
		i++;
	}
}

void	move_ant(t_farm *farm)
{
	size_t	nbr;
	t_node	*ant_node;
	t_ant	*ant;
	t_room	*room;
	size_t	finish;

	nbr = 1;
	while (1)
	{
		if (nbr <= farm->ant_num)
			create_ant(farm, &nbr);
		finish = 0;
		ant_node = farm->ant;
		while (ant_node)
		{
			ant = ant_node->content;
			if (ant->path)
			{
				room = ((t_node*)ant->path)->content;
				ft_printf("L%lu-%s ", ant->nbr, room->name);
				ant->path = ant->path->next;
			}
			else
				finish++;
			ant_node = ant_node->next;
		}
		if (finish == farm->ant_num)
			break ;
		ft_printf("\n");
	}
}
