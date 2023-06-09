#include "monty.h"

/**
 * _push - pushes an element to the stack.
 * @stack: double pointer
 * @line_number: line number of opcode
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int value;

	token = strtok(NULL, " \t\n");

	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!_isdigit(token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(token);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error, malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
