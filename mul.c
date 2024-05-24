#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = (*stack)->next;

	next->n *= top->n;

	pop(stack, line_number);
}
