/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:31:30 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/27 13:54:38 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*find_room(t_farm *farm, char *name)
{
	t_list	*current;

	current = farm->room->head;
	while (current)
	{
		if (ft_strcmp(((t_room *)current->content)->name, name) == 0)
			return (current->content);
		current = current->next;
	}
	return (NULL);
}

void	print_graph(t_farm *farm)
{
	t_list	*current;
	t_room	*room;
	t_list	*edge;

	ft_printf("number of ants = %d\n", farm->ant);
	ft_printf("start = %s\n", ((t_room *)farm->start)->name);
	ft_printf("end = %s\n", ((t_room *)farm->end)->name);
	current = farm->room->head;
	while (current)
	{
		room = (t_room *)current->content;
		ft_printf("%s ", room->name);
		edge = room->edge->head;
		while (edge)
		{
			ft_printf("-> %s", ((t_room *)edge->content)->name);
			edge = edge->next;
		}
		ft_printf("\n");
		current = current->next;
	}
}

void	create_graph(t_farm *farm)
{
	t_list	*current;
	t_room	*room1;
	t_room	*room2;

	current = farm->link->head;
	while (current)
	{
		room1 = find_room(farm, ((t_link *)current->content)->src);
		room2 = find_room(farm, ((t_link *)current->content)->dst);
		if (!room1 || !room2)
			ft_error();
		ft_stack_push(room1->edge, room2);
		ft_stack_push(room2->edge, room1);
		current = current->next;
	}
}
