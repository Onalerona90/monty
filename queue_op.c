#include "monty.h"

/**
 * queue_op - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void queue_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (data_structure_mode == STACK)
	{
		data_structure_mode = QUEUE;
		return;
	}
}
