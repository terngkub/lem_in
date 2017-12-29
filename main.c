/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:36:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 18:51:49 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_farm	farm;

	farm_init(&farm);
	read_input(&farm);
	get_all_path(&farm);
	allocate_ant(&farm);
	move_ant(&farm);
	clean_all(&farm);
	return (0);
}
