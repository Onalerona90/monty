#include "monty.h"

/**
 * main - Entry point
*/

int main(void)
{
	stack_t *stack = NULL;
	unsigned int i;
    int j = 0;
    char *opcode;

	for (i = 0; opcodes[i] != NULL; i++)
    {
        opcode = strtok(opcodes[i], " \n");

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

	while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

	return 0;
}
