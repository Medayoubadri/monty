#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number in the bytecode file
 *
 * Description: If the stack is empty, prints an error message and exits.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
