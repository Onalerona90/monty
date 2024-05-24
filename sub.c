#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = (*stack)->next;

	next->n -= top->n;

	pop(stack, line_number);
}
