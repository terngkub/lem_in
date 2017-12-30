/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:35:55 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 20:33:29 by nkamolba         ###   ########.fr       */
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
			path = farm->all_path;
			j = 0;
			while (j++ < i)
				path = path->next;
			ant->path = path->content;
			ant->path_color = (j % 6) + 30;
			farm->alloc[i]--;
			*nbr += 1;
			ft_node_pushback_e(&farm->ant, ant);
		}
		i++;
	}
}

void	print_move(t_farm *farm, t_node *ant_node, size_t *finish)
{
	t_room	*room;
	t_ant	*ant;

	ant = ant_node->content;
	if (ant->path)
	{
		room = ((t_node*)ant->path)->content;
		if (farm->color_ant)
			ft_printf("\x1b[%lum", ant->nbr % 6 + 90);
		ft_printf("L%lu\x1b[0m-", ant->nbr);
		if (farm->color_path)
			ft_printf("\x1b[%lum", ant->path_color);
		ft_printf("%s\x1b[0m ", room->name);
		ant->path = ant->path->next;
	}
	else
		*finish += 1;
}

void	move_ant(t_farm *farm)
{
	size_t	nbr;
	t_node	*ant_node;
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
			print_move(farm, ant_node, &finish);
			ant_node = ant_node->next;
		}
		if (finish == farm->ant_num)
			break ;
		ft_printf("\n");
	}
}
