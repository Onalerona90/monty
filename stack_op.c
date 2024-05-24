#include "monty.h"

/**
 * stack_op - Sets the format of the data to a stack (LIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (data_structure_mode == QUEUE)
	{
		data_structure_mode = STACK;
		return;
	}
}
