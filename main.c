/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:36:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 14:03:53 by nkamolba         ###   ########.fr       */
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
*/

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

int	main(void)
{
	t_farm	farm;
	t_node	*path;

	farm.room = NULL;
	farm.blocked = NULL;
	read_input(&farm);
	print_graph(&farm);
	ft_printf("paths\n");
	get_all_paths(&farm);
	return (0);
}
