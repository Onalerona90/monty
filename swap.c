#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = (*stack)->next;

	top->next = next->next;
	if (next->next != NULL)
	{
		next->next->prev = top;
	}

	next->next = top;
	top->prev = next;
	next->prev = NULL;

	*stack = next;
}
