#include "monty.h"

/**
* free_stack - Frees a stack (doubly linked list)
* @stack: The stack to be freed
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
