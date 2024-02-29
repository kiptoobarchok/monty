#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * op_push - Implements the push opcode.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the input file.
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	int value = atoi(arg);

	if (!arg || !line_number)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		 exit(EXIT_FAILURE);
	}

	op_push(stack, value); /* Assuming push function is defined */
}

/**
 * op_pall - Implements the pall opcode.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the input file.
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
	current = current->next;
	}
}
