#include "monty.h"
#include <stdlib.h>

/**
 * op_pop - Implements the pop opcode.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the input file.
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack)
	(*stack)->prev = NULL;

	free(temp);
}
