#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (
		current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127
	)
	{
		if (current->n > 0 && current->n <= 127)
			putchar(current->n);
		else
		{
			fprintf(stderr, "L%u: can't pstr, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
		current = current->next;
	}
	putchar('\n');
}
