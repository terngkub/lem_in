/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:59:51 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 15:11:43 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(1);
}

int		ft_isalldigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	print_path(t_node *node)
{
	ft_printf("%s", ((t_room *)node->content)->name);
	node = node->next;
	while (node)
	{
		ft_printf(" -> %s", ((t_room *)node->content)->name);
		node = node->next;
	}
	ft_printf("\n");
}

void	print_graph(t_farm *farm)
{
	t_node	*node_room;
	t_room	*room;
	t_node	*node_edge;
	t_room	*edge;

	ft_printf("number of ants = %d\n", farm->ant_amount);
	ft_printf("start = %s\n", farm->start->name);
	ft_printf("end = %s\n", farm->end->name);
	node_room = farm->room;
	while (node_room)
	{
		room = node_room->content;
		ft_printf("%s", room->name);
		node_edge = room->edge;
		while (node_edge)
		{
			edge = node_edge->content;
			ft_printf(" -> %s", edge->name);
			node_edge = node_edge->next;
		}
		ft_printf("\n");
		node_room = node_room->next;
	}
}
