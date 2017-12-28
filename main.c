/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:36:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/28 18:04:08 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_farm	farm;
	t_node	*all_paths;
	size_t	*lag_array;
	size_t	i;

	farm.room = NULL;
	farm.blocked = NULL;
	read_input(&farm);
	print_graph(&farm);
	ft_printf("paths\n");
	all_paths = get_all_paths(&farm);
	lag_array = create_lag_array(all_paths);
	clean_all(&farm, all_paths);
	return (0);
}
