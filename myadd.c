#include "monty.h"

/**
 * op_add - Implements the add opcode.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the input file.
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	op_pop(stack, line_number);
}