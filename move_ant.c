/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:35:55 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 13:52:43 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	ft_node_len(t_node *node)
{
	size_t	len;

	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

size_t	*create_lag_array(t_farm *farm, t_node *all_path)
{
	size_t	len;
	size_t	*arr;
	size_t	i;
	size_t	max;

	len = ft_node_len(all_path);
	if (!(arr = (size_t *)malloc(sizeof(size_t) * len)))
		ft_error();
	i = 0;
	while (i < len)
	{
		arr[i++] = ft_node_len(all_path->content);
		all_path = all_path->next;
	}
	max = arr[i - 1];
	i = 0;
	while (i < len)
	{
		arr[i] = max - arr[i];
		i++;
	}
	allocate_ant(farm, len, arr);
	return (arr);
}

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

void	allocate_ant(t_farm *farm, size_t len, size_t *arr)
{
	size_t	i;
	size_t	ant_left;
	size_t	sum;
	size_t	remainder;

	sum = array_sum(arr, len);
	if (farm->ant >= sum)
	{
		ant_left = farm->ant - sum;
		remainder = ant_left - (ant_left / len) * len;
		array_increment(arr, len, ant_left / len);
		array_increment(arr, remainder, 1);
	}
	else
	{
		i = len - 1;
		while (farm->ant < sum)
		{
			if (arr[i] > 0)
				arr[i]--;
				sum--;
			}
			i = (i == 0) ? len - 1 : i - 1;
		}
	}
	i = 0;
	while (i < len)
		ft_printf("%d\n", arr[i++]);
}

void	create_ant(t_node *all_path, size_t *arr, t_node *ant_queue, size_t *nbr)
{
	while (i < len)
	{
		if (arr[i] > 0)
		{
			if (!(ant = (t_ant *)malloc(sizeof(t_ant))))
				ft_error();
			ant->nbr = *nbr;
			path = all_path;
			j = 0;
			while (j++ < i)
				path = path->next;
			ant->path = path;
			arr[i]--;
			*nbr += 1;
			ft_node_enqueue(ant_queue, ft_node_create(ant));
		}
		i++;
	}
}

/*
void	move_ant(t_farm *farm, t_node *all_path)
{
	t_node	*ant;

	i = 0;
	while (1)
	{
		if (i < farm->ant)
			create_ant(ant, i);
		finish = 1;
		while (ant)
		{
			if (((t_room *)ant->path->content) != farm->end)
			{
				//path = path->next;
				//print ant
				//print room
			}
			else
				finish = 0;
		}
		if (finish == 1)
			break;
		i++;
	}
}
*/
