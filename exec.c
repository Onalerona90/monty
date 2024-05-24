#include "monty.h"

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
