#include "monty.h"
#include <stdlib.h>

/**
 * op_swap - Implements the swap opcode.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the input file.
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
