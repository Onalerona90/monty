#include "monty.h"

/**
 * queue_op - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

data_structure_t data_structure_mode = STACK;

void queue_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_structure_mode = QUEUE;
}
