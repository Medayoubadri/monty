#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number in the bytecode file
 *
 * Description: If the stack contains fewer than two elements, prints an error
 * message and exits. The result is stored in the second top element,
 * and the top element is removed.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	(*stack)->next->n = sum;

	pop(stack, line_number);
}

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number in the bytecode file
 *
 * Description: If the stack contains fewer than two elements, prints an error
 * message and exits. The result is stored in the second top element,
 * and the top element is removed.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	/* Check if there are fewer than two elements on the stack */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Subtract the top element from the second top element */
	diff = (*stack)->next->n - (*stack)->n;

	/* Store the result in the second element */
	(*stack)->next->n = diff;

	/* Remove the top element */
	pop(stack, line_number);
}

/**
 * div_op - Divides the second top element of the stack by the top element
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number in the bytecode file
 *
 * Description: If the stack contains fewer than two elements, prints an error
 * message and exits. If the top element is 0, prints an error and exits.
 * The result is stored in the second top element,the top element is removed.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;

	(*stack)->next->n = quotient;

	pop(stack, line_number);
}

/**
 * mul - Multiplies the second top element of the stack with the top element
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number in the bytecode file
 *
 * Description: If the stack contains fewer than two elements, prints an error
 * message and exits. The result is stored in the second top element, and
 * the top element is removed.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;

	(*stack)->next->n = product;

	pop(stack, line_number);
}

/**
 * mod - Computes the remainder of the division of the second top element
 * by the top element of the stack.
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: The current line number in the bytecode file
 *
 * Description: If the stack contains fewer than two elements, prints an error
 * message and exits. If the top element is 0 (division by zero), prints
 * an error message and exits.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;

	(*stack)->next->n = remainder;

	pop(stack, line_number);
}
