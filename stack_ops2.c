#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: Line number in the bytecode file
 *
 * Description: The top element becomes the last,
 * and the second element becomes the first.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = temp->next;
	(*stack)->prev = NULL;

	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
}
