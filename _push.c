#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int value;

	token = strtok(NULL, " \t\n");

	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		ex_error(stack);
	}

	if (!_isdigit(token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		ex_error(stack);
	}

	value = atoi(token);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error, malloc failed\n");
		ex_error(stack);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
