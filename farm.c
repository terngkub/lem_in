/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:35:52 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 18:36:36 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	farm_init(t_farm *farm)
{
	farm->ant_num = 0;
	farm->start = NULL;
	farm->end = NULL;
	farm->room = NULL;
	farm->blocked = NULL;
	farm->all_path = NULL;
	farm->path_num = 0;
	farm->ant = NULL;
	farm->alloc = 0;
}
