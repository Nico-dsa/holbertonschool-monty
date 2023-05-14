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
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		ex_error(&stack);
	}
	read_file(argv[1], &stack);
	free_dlistint(stack);
	return (0);
}
