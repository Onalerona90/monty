#include "monty.h"

/**
 * queue_op - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void queue_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *last;

	(void)stack;
	(void)line_number;

	if (data_structure_mode == STACK)
	{
		temp = *stack;
		last = NULL;

		if (*stack == NULL)
			return;

		while (temp->next != NULL)
			temp = temp->next;

		last = temp;
		while (last->prev != NULL)
		{
			last->prev->next = last->next;
			if (last->next != NULL)
				last->next->prev = last->prev;
			last->next = last->prev;
			last->prev = NULL;
			last->next->prev = last;
			*stack = last;
			last = last->next;
		}
		data_structure_mode = QUEUE;
	}
}
