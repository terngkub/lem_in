/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:36:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 20:34:36 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_farm	farm;

	if (argc > 2)
		ft_error("too much argument");
	farm_init(&farm);
	read_bonus(&farm, argv[1]);
	read_input(&farm);
	get_all_path(&farm);
	allocate_ant(&farm);
	ft_printf("%s\n", farm.input);
	if (farm.print_all_path)
		print_all_path(&farm);
	if (farm.print_allocation)
		print_allocation(&farm);
	move_ant(&farm);
	clean_all(&farm);
	return (0);
}
