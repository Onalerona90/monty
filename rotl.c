#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}
