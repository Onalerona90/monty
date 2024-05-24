#include "monty.h"

/**
 * execute - Executes a given line of code by finding and
 * calling the corresponding function.
 * @line: The line of code to execute
 * @line_number: The line number in the source file
 * @stack: A pointer to the top of the stack
*/

void execute(char *line, unsigned int line_number, stack_t **stack)
{
	int j;
	char *opcode;

	opcode = strtok(line, " \n");

	if (opcode == NULL || opcode[0] == '#')
		return;

	for (j = 0; instructions[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, instructions[j].opcode) == 0)
		{
			instructions[j].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
