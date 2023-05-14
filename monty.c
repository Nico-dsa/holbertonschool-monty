#include "monty.h"

/**
 * main - driver function for monty program
 * @argc: num of arguments
 * @argv: opcode file
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t line_buf = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &line_buf, file) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;
		get_func(opcode, &stack, line_number);
	}
	free(line);
	fclose(file);
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
