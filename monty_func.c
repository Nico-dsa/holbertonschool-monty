#include "monty.h"

/**
 * ex_error - exit to error
 * @stack: pointer to the head of a stack
 *
 */

void ex_error(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * read_file - read a file and run command
 * @filename: path to file
 * @stack: pointer to the top of the stack
 *
 */

void read_file(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	get_op_func s;
	int line_count = 1;
	int check;
	int read;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		ex_error(stack);
	}

	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = parse_line(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_func(line);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_count, line);
			ex_error(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}

/**
 * parse_line - parse a line for an opcode or an argument
 * @line: line to be parsed
 *
 * Return: the opcode or NULL
 */

char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n");
	if (op_code == NULL)
		return (NULL);
	return (op_code);
}

/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */

void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * _isdigit - function that check for a digit
 * @str: string to check
 *
 * Return: 1 if its an integer, else 0
 */

int _isdigit(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	if (*str == '\0')
		return (0);
	
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (-1);
}
