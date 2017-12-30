/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:53:57 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 19:19:51 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_next_line_e(int fd, char **line)
{
	int		gnl;

	gnl = get_next_line(fd, line);
	if (gnl == -1)
		ft_error("get_next_line failed");
	else if (gnl == 0)
		ft_error("insufficient input");
}

void	get_next_line_skip(int fd, char **line, int start_end)
{
	char	*str;

	while (1)
	{
		get_next_line_e(fd, line);
		str = *line;
		if (*str && *str != '#')
			break ;
		if ((ft_strcmp(str, "##start") == 0 || ft_strcmp(str, "##end") == 0)
				&& start_end == 1)
			ft_error("no room under start/end comment");
		free(str);
	}
}

void	read_comment(t_farm *farm, char *str)
{
	char	*next_room;

	if (ft_strcmp(str + 2, "start") == 0)
	{
		if (farm->start)
			ft_error("duplicated start room");
		get_next_line_skip(0, &next_room, 1);
		farm->input = ft_strfreecat_back_e(&farm->input, str);
		farm->input = ft_strfreecat_back_e(&farm->input, "\n");
		read_room(farm, next_room);
		farm->start = farm->room->content;
		free(next_room);
	}
	else if (ft_strcmp(str + 2, "end") == 0)
	{
		if (farm->end)
			ft_error("duplicated end room");
		get_next_line_skip(0, &next_room, 1);
		farm->input = ft_strfreecat_back_e(&farm->input, str);
		farm->input = ft_strfreecat_back_e(&farm->input, "\n");
		read_room(farm, next_room);
		farm->end = farm->room->content;
		free(next_room);
	}
}

void	read_ant(t_farm *farm)
{
	char	*str;

	get_next_line_skip(0, &str, 0);
	if (!ft_isalldigit(str))
		ft_error("ant number input isn't valid");
	farm->ant_num = ft_atoi(str);
	if (farm->ant_num <= 0)
		ft_error("ant number is less than 1");
	farm->input = ft_strdup_e(str);
	farm->input = ft_strfreecat_back_e(&farm->input, "\n");
	free(str);
}

void	read_input(t_farm *farm)
{
	int		gnl;
	char	*str;

	read_ant(farm);
	while ((gnl = get_next_line(0, &str)) > 0)
	{
		if (*str && *(str + 1) && *str == '#' && *(str + 1) == '#')
			read_comment(farm, str);
		else if (*str && *str == '#')
			;
		else if (ft_strchr(str, '-'))
			read_link(farm, str);
		else
			read_room(farm, str);
		free(str);
	}
	if (gnl == -1)
		ft_error("get_next_line failed");
}
