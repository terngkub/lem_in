/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:23:15 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 16:43:01 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	array_increment(size_t *arr, size_t len, size_t increment)
{
	size_t	i;

	i = 0;
	while (i < len)
		arr[i++] += increment;
}

size_t	array_sum(size_t *arr, size_t len)
{
	size_t	sum;
	size_t	i;

	sum = 0;
	i = 0;
	while (i < len)
		sum += arr[i++];
	return (sum);
}

void	compute_lag(t_farm *farm)
{
	t_node	*path;
	size_t	i;
	size_t	max;

	path = farm->all_path;
	if (!(farm->alloc = (size_t *)malloc(sizeof(size_t) * farm->path_num)))
		ft_error();
	i = 0;
	while (i < farm->path_num)
	{
		farm->alloc[i++] = ft_node_len(path->content);
		path = path->next;
	}
	max = farm->alloc[i - 1];
	i = 0;
	while (i < farm->path_num)
	{
		farm->alloc[i] = max - farm->alloc[i];
		i++;
	}
}

void	allocate_ant(t_farm *farm)
{
	size_t	i;
	size_t	ant_left;
	size_t	sum;
	size_t	remainder;

	compute_lag(farm);
	sum = array_sum(farm->alloc, farm->path_num);
	if (farm->ant_num >= sum)
	{
		ant_left = farm->ant_num - sum;
		remainder = ant_left - (ant_left / farm->path_num) * farm->path_num;
		array_increment(farm->alloc, farm->path_num, ant_left / farm->path_num);
		array_increment(farm->alloc, remainder, 1);
	}
	else
	{
		i = farm->path_num - 1;
		while (farm->ant_num < sum)
		{
			sum = farm->alloc[i] > 0 ? sum - 1 : sum;
			if (farm->alloc[i] > 0)
				farm->alloc[i]--;
			i = (i == 0) ? farm->path_num - 1 : i - 1;
		}
	}
	i = 0;
	while (i < farm->path_num)
	{
		ft_printf("path %lu: %lu\n", i, farm->alloc[i]);
		i++;
	}
}
