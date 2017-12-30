/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:36:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 19:37:43 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	t_farm	farm;

	farm_init(&farm);
	read_input(&farm);
	get_all_path(&farm);
	allocate_ant(&farm);
	ft_printf("%s\n", farm.input);
	print_all_path(&farm);
	print_allocation(&farm);
	move_ant(&farm);
	clean_all(&farm);
	return (0);
}
