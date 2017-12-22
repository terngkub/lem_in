#include "lem_in.h"

t_stack_list	*create_stack_list(void)
{
	t_stack_list	*stack_list;

	if (!(stack_list = (t_stack_list *)malloc(sizeof(t_stack_list))))
		exit(1);
	stack_list->stack = NULL;
	stack_list->next = NULL;
	return (stack_list);
}

void			*push_stack(t_stack_list *stack_list, t_stack *stack)
{

}
