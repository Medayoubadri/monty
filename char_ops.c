#include "monty.h"

/**
* pchar - Prints the char at the top of the stack
* @stack: Pointer to the stack (doubly linked list)
* @line_number: The current line number in the bytecode file
*
* Description: The integer stored at the top of the stack is treated as
* the ASCII value of the character to be printed.
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

#include "monty.h"

/**
* pstr - Prints the string starting at the top of the stack
* @stack: Pointer to the stack (doubly linked list)
* @line_number: The current line number in the bytecode file
*
* Description: The integer stored in each element of the stack is treated
* as the ASCII value of the character to be printed.
* If the stack is empty, it prints a new line.
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		if (current->n <= 0 || current->n > 127)
			break;

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
