/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:36:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 17:13:55 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ant(t_farm *farm)
{
	t_node	*ant;

	ft_printf("____________________________________\n");
	ant = farm->ant;
	while (ant)
	{
		ft_printf("ant no. %lu\n", (((t_ant *)ant->content)->nbr));
		ant = ant->next;
	}
}
int	main(void)
{
	t_farm	farm;

	farm.room = NULL;
	farm.blocked = NULL;
	farm.all_path = NULL;
	farm.path_num = 0;
	farm.ant = NULL;
	read_input(&farm);
	print_graph(&farm);
	ft_printf("______________________________________\n");
	ft_printf("paths\n");
	get_all_path(&farm);
	ft_printf("______________________________________\n");
	allocate_ant(&farm);
	ft_printf("______________________________________\n");
	move_ant(&farm);
	clean_all(&farm, farm.all_path);
	return (0);
}
