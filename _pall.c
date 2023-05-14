#include "monty.h"

/**
 *  _pall - prints all the values on the stack, starting from top of the stack
 * @stack: double pointer
 * @line_number: line number of opcode
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *node = *stack;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
