#include "monty.h"

/**
 * push - Adds a new element to the stack.
 * @stack: Double pointer to the stack (head of the stack).
 * @line_number: The line number where the instruction occurs.
 * @arg: The argument for the push opcode.
 *
 * Description: Pushes an integer onto the stack. If no argument or invalid
 * integer is provided, exits with an error.
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int value;
	
	if (arg == NULL || (atoi(arg) == 0 && strcmp(arg, "0") != 0))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

