#include "monty.h"

void process_line(char *line, unsigned int line_number, stack_t **stack);

/**
* main - entry point
* @argv: list of arguments passed to the program
* @argc: amoout of args
*
* Return: nothing
*/

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;

	unsigned int line_number = 0;

	stack_t *stack = NULL;

	line = malloc(1024);
	file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, 1024, file) != NULL)
	{
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		line_number++;
		process_line(line, line_number, &stack);
	}

	free(line);
	fclose(file);
	free_stack(stack);
	return (0);
}

/**
* process_line - Parses and processes each line of the file
* @line: The current line from the file
* @line_number: The line number being processed
* @stack: The stack (doubly linked list) being manipulated
*/
void process_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode;
	char *arg = NULL;
	int i = 0;

	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"nop", nop},
		{NULL, NULL}
	};

	clean_line(line);

	if (line[0] == '#' || line[0] == '\n' || line[0] == '\0')
		return;

	opcode = strtok(line, " \n\t");
	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \n\t");
		if (arg == NULL || !check_int(arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, line_number, arg);
		return;
	}

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
