/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:53:57 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 16:06:51 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_comment(t_farm *farm, char *str)
{
	char	*next_room;

	if (ft_strcmp(str + 2, "start") == 0)
	{
		get_next_line(0, &next_room);
		read_room(farm, next_room);
		farm->start = farm->room->content;
		free(next_room);
	}
	else if (ft_strcmp(str + 2, "end") == 0)
	{
		get_next_line(0, &next_room);
		read_room(farm, next_room);
		farm->end = farm->room->content;
		free(next_room);
	}
}

void	read_ant(t_farm *farm)
{
	char	*str;

	get_next_line(0, &str);
	if (!ft_isalldigit(str))
		ft_error();
	farm->ant = ft_atoi(str);
	free(str);
}

void	read_input(t_farm *farm)
{
	char	*str;

	read_ant(farm);
	while (get_next_line(0, &str) > 0)
	{
		if (*str && *(str + 1) && *str == '#' && *(str + 1) == '#')
			read_comment(farm, str);
		else if (ft_strchr(str, '-'))
			read_link(farm, str);
		else
			read_room(farm, str);
		free(str);
	}
}
