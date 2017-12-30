/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:35:52 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 20:34:29 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	farm_init(t_farm *farm)
{
	farm->input = NULL;
	farm->ant_num = 0;
	farm->start = NULL;
	farm->end = NULL;
	farm->room = NULL;
	farm->blocked = NULL;
	farm->all_path = NULL;
	farm->path_num = 0;
	farm->ant = NULL;
	farm->alloc = 0;
	farm->print_all_path = 0;
	farm->print_allocation = 0;
	farm->color_path = 0;
	farm->color_ant = 0;
}

void	read_bonus(t_farm *farm, char *str)
{
	if (!str)
		return ;
	if (str[0] != '-' || !str[1])
		ft_error("wrong flag. usage: ./lem-n -[p/a/c/k]");
	str++;
	while (*str)
	{
		if (*str == 'p')
			farm->print_all_path = 1;
		else if (*str == 'a')
			farm->print_allocation = 1;
		else if (*str == 'c')
			farm->color_path = 1;
		else if (*str == 'k')
			farm->color_ant = 1;
		else
			ft_error("wrong flag. usage: ./lem-n -[p/a/c/k]");
		str++;
	}
}
