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
 * pop - Removes the top element of the stack
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number in the bytecode file
 *
 * Description: If the stack is empty, prints an error message and exits.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}


/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number in the bytecode file
 *
 * Description: If the stack contains fewer than two elements,
 * prints an error message and exits.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
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
