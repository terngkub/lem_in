/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:36:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 12:22:12 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
void	ft_stack_delete(t_stack *stack, void (*del)(void *, size_t))
{
	ft_lstdel(&(stack->head), del);
	free(stack);
}
*/
void	clear_split(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/*
void	clear_edge(void *content, size_t content_size)
{
	free(content);
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

void	print_path(t_queue *queue)
{
	t_list	*node;

	node = queue->head;
	while (node)
	{
		ft_printf("%s\n", ((t_room *)node->content)->name);
		node = node->next;
	}
}

*/
int	main(void)
{
	t_farm	farm;
	t_queue	*path;
	t_room	*room;

	farm.room = NULL;
	farm.blocked = NULL;
	read_input(&farm);
	print_graph(&farm);
	set_room(&farm);
	//bfs(&farm);
	//path = get_path(&farm);
	//print_path(path);
	//clear_farm(&farm);
	return (0);
}
