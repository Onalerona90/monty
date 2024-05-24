#include "monty.h"

/**
 * main - Entry point
*/

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int i;
    char *opcode;

	for (i = 0; opcodes[i] != NULL; i++)
    {
        opcode = strtok(opcodes[i], " \n");

        int j = 0;
        while (instructions[j].opcode != NULL)
        {
            if (strcmp(opcode, instructions[j].opcode) == 0)
            {
                instructions[j].f(&stack, i + 1);
                break;
            }
            j++;
        }
    }
	return 0;
}
