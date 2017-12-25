/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:53:57 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/25 18:24:14 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_comment(t_farm *farm, char *str)
{
	if (start)
	{
		read_room(farm);
		farm->start = room_name;
	}
	else if (end)
	{
		read_room(farm);
		farm->start = room_name;
	}
}

void	read_link(t_farm *farm, char *str)
{
}

void	read_room(t_farm *farm, char *str)
{
	ft_count_char(*str
	room->name = ;
	room->x = ;
	room->y = ;
	room->link = ft_stack_create();
}

void	read_input(t_farm *farm)
{
	t_room	*room;
	char	*str;

	while (get_next_line(1, &str) > 0)
	{
		if (*str == '#')
			read_comment(farm, str);
		else if (ft_strchr(str, '-'))
			read_link(farm, str);
		else
			read_room(farm, str);
	}
}
	//read from stdin with gnl
	//store each one in room queue and link queue
	//after finish reading create graph using room queue
	//add edge by using link queue
	//free link queue
	//
	//room structure
	//	name
	//	x
	//	y
	//	link
	//	
	//ant_farm
	//	start
	//	end
	//	room 
	//	link
