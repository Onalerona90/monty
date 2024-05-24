#include "monty.h"

/**
 * div - Divides the second top element of the stack by the top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = (*stack)->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	next->n /= top->n;

	pop(stack, line_number);
}
