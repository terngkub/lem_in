/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:36:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 16:17:55 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_farm	farm;
	t_node	*all_paths;

	farm.room = NULL;
	farm.blocked = NULL;
	read_input(&farm);
	print_graph(&farm);
	ft_printf("paths\n");
	all_paths = get_all_paths(&farm);
	clean_all(&farm, all_paths);
	return (0);
}
