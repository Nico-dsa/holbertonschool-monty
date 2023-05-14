#include "monty.h"

/**
 * get_func - check opcode and return the correct function
 * @str: opcode
 *
 * Return: a function or NULL on failure
 */

get_op_func get_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	for (i = 0; instruct[i].opcode != NULL; i++)
	{
		if (*instruct[i].opcode == *str)
			return (instruct[i].f);
	}
	return (NULL);
}
