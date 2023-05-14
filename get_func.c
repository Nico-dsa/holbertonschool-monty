#include "monty.h"

/**
 * get_func - check opcode and return the correct function
 * @opcode: opcode
 * @stack: double pointer
 * @line_number: line number of opcode
 *
 * Return: 0
 */

void get_func(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL},
	};
	int i;

	for (i = 0; instruct[i].opcode != NULL; i++)
	{
		if (strcmp(instruct[i].opcode, opcode) == 0)
		{
			instruct[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
