#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void(*get_op_func)(stack_t **stack, unsigned int line_number);

void ex_error(stack_t **stack);
void read_file(char *filename, stack_t **stack);
char *parse_line(char *line);
int main(int argc, char **argv);
void free_dlistint(stack_t *head);
void _pall(stack_t **stack, unsigned int line_number);
int _isdigit(const char *str);
void _push(stack_t **stack, unsigned int line_number);
get_op_func get_func(char *str);

#endif
