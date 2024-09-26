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


/**
* clean_line - Cleans the line by removing trailing characters like $
* @line: The line to clean
*/
void clean_line(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (!isprint(line[i]) || line[i] == '$')
		{
			line[i] = '\0';
			break;
		}
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
