#include "monty.h"

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
