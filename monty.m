#include "monty.h"
#define MAX_LINE_LENGTH 1024

instruction_t instruction_s[] = {
	{"push", op_push},
	{"pall", op_pall},
	{"add", op_add},
	{"pint", op_pint},
	{"nop", op_nop},
	{"pop", op_pop},
	{NULL, NULL} /* End of the array */
};

/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: Always 0 (success).
 */

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;
	char *opcode = strtok(line, " \t\n");

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		if (opcode && opcode[0] != '#')
		{
			int i;

			for (i = 0; instruction_s[i].opcode; i++)
			{
				if (strcmp(opcode, instruction_s[i].opcode) == 0)
				{
					instruction_s[i].f(&stack, line_number);
					break;
				}
			}
		if (!instruction_s[i].opcode)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		}
	}
	fclose(file);
	return (0);
}