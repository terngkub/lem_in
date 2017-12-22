/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:03:36 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/22 18:04:10 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue			*create_queue(void)
{
	t_queue			*queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	queue->head = NULL;
	queue->tail = NULL;
	return (queue);
}

void			push_front(t_queue *queue, int dst)
{
	t_adjlist_node	*node;

	if (!queue)
		return ;
	node = create_adjlist_node(dst);
	if (!(queue->head))
		queue->tail = node;
	else
		node->next = queue->head;
	queue->head = node;
	
}

void			enqueue(t_queue *queue, int dst)
{
	t_adjlist_node	*node;

	if (!queue)
		return ;
	node = create_adjlist_node(dst);
	if (!(queue->head))
		queue->head = node;
	else
		queue->tail->next = node;
	queue->tail = node;
}

int				dequeue(t_queue *queue)
{
	t_adjlist_node	*node;
	int				dst;

	if (!queue || !(queue->head))
		return (0);
	node = queue->head;
	dst = node->dst;
	if (queue->head == queue->tail)
		queue->tail = NULL;
	queue->head = queue->head->next;
	free(node);
	return (dst);
}
