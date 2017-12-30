/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:35:55 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 19:57:02 by nkamolba         ###   ########.fr       */
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
			ant = (t_ant *)ft_malloc_e(sizeof(t_ant));
			ant->nbr = *nbr;
			ant->ant_color = (*nbr % 6) + 31;
			path = farm->all_path;
			j = 0;
			while (j++ < i)
				path = path->next;
			ant->path = path->content;
			ant->path_color = (j % 6) + 90;
			farm->alloc[i]--;
			*nbr += 1;
			ft_node_pushback_e(&farm->ant, ant);
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
				ft_printf("\x1b[%lumL%lu\x1b[0m-\x1b[%lum%s\x1b[0m ", 
						ant->ant_color, ant->nbr, ant->path_color, room->name);
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
