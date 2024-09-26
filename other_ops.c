#include "monty.h"

/**
 * nop - Does nothing
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number in the bytecode file
 *
 * Description: This function literally does nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}


/**
 * stack - Sets the format to stack (LIFO)
 * @stack: Pointer to the stack
 * @line_number: Line number in the bytecode file
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_format = 0;
}

/**
 * queue - Sets the format to queue (FIFO)
 * @stack: Pointer to the stack
 * @line_number: Line number in the bytecode file
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_format = 1;
}

