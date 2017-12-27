/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:36:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/27 13:52:43 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_stack_delete(t_stack *stack, void (*del)(void *, size_t))
{
	ft_lstdel(&(stack->head), del);
	free(stack);
}

void	clear_split(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	clear_edge(void *content, size_t content_size)
{
}

void	clear_link(void *content, size_t content_size)
{
	t_link 	*link;

	link = (t_link *)content;
	free(link->src);
	free(link->dst);
	free(link);
}

void	clear_room(void *content, size_t content_size)
{
	t_room	*room;

	room = (t_room *)content;
	free(room->name);
	ft_stack_delete(room->edge, clear_edge);
	free(room);
}

void	clear_farm(t_farm *farm)
{
	ft_stack_delete(farm->link, clear_link);
	ft_stack_delete(farm->room, clear_room);
}

int	main(void)
{
	t_farm	farm;

	farm.room = ft_stack_create(sizeof(t_room));
	farm.link = ft_stack_create(sizeof(t_link));
	read_input(&farm);
	create_graph(&farm);
	print_graph(&farm);
	clear_farm(&farm);
	return (0);
}
