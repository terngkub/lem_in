/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:59:51 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 19:58:26 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


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
	ft_printf("\x1b[0m\n");
}

void	print_all_path(t_farm *farm)
{
	t_node	*node;
	int		i;

	ft_printf("Path:\n");
	node = farm->all_path;
	i = 0;
	while (node)
	{
		ft_printf("\x1b[%dmpath%d: ", i % 6 + 91, i);
		i++;
		print_path(node->content);
		node = node->next;
	}
	ft_printf("\n");
}

void	print_allocation(t_farm *farm)
{
	size_t 	i;

	ft_printf("Allocation:\n");
	i = 0;
	while (i < farm->path_num)
	{
		ft_printf("\x1b[%dmpath%lu: %lu\x1b[0m\n", i % 6 + 91, i, farm->alloc[i]);
		i++;
	}
	ft_printf("\n");
}
