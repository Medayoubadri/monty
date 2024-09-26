#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number in the bytecode file
 * @arg: The argument (integer) to push to the stack
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	int n;
	stack_t *new_node;

	if (arg == NULL || check_int(arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack, starting from the top
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * check_int - Checks if a string represents a valid integer
 * @arg: The string to check
 * Return: 1 if the string is a valid integer, otherwise 0
 */
int check_int(char *arg)
{
	int i = 0;

	if (arg[0] == '-' || arg[0] == '+')
		i++;

	for (; arg[i] != '\0'; i++)
	{
		if (!isdigit(arg[i]))
			return (0);
	}

	return (1);
}
