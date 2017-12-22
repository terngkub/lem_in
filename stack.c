/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 19:14:23 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/22 23:13:58 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	stack->size = 0;
	stack->head = NULL;
	return (stack);
}

void	push(t_stack *stack, int n)
{
	t_node	*node;

	if (!stack)
		exit(1);
	node = create_node(n);
	if (stack->size > 0)
		node->next = stack->head;
	stack->head = node;
	stack->size++;
}

int		pop(t_stack *stack)
{
	t_node	*node;
	int		n;

	if (!stack || stack->size <= 0)
		exit(1);
	node = stack->head;
	n = node->n;
	stack->head = node->next;
	free(node);
	stack->size--;
	return (n);
}

void	print_stack(t_stack *stack)
{
	t_node *node;

	if (stack->size == 0)
		return ;
	node = stack->head;
	ft_printf("%d", node->n);
	node = node->next;
	while (node)
	{
		ft_printf(" -> %d", node->n);
		node = node->next;
	}
	ft_printf("\n");
}
