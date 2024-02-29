#include "monty.h"
#include <stdlib.h>

/**
 * op_pint - Implements the pint opcode.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the input file.
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
