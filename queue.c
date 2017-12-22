/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:03:36 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/22 23:08:22 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*create_queue(void)
{
	t_queue	*queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		exit(1);
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;
	return (queue);
}

void	enqueue(t_queue *queue, int n)
{
	t_node	*node;

	if (!queue)
		exit(1);
	node = create_node(n);
	if (queue->size > 0)
		queue->tail->next = node;
	else
		queue->head = node;
	queue->tail = node;
	queue->size++;
}

int		dequeue(t_queue *queue)
{
	t_node	*node;
	int		n;

	if (!queue || !(queue->head))
		exit(1);
	node = queue->head;
	n = node->n;
	if (queue->size == 1)
		queue->tail = NULL;
	queue->head = queue->head->next;
	free(node);
	queue->size--;
	return (n);
}

void	print_queue(t_queue *queue)
{
	t_node	*node;

	if (queue->size == 0)
		return ;
	node = queue->head;
	ft_printf("%d", node->n);
	node = node->next;
	while (node)
	{
		ft_printf(" -> %d", node->n);
		node = node->next;
	}
	ft_printf("\n");
}
