#include "monty.h"

/**
 * stack_op - Sets the format of the data to a stack (LIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void stack_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)stack;
	(void)line_number;

	if (data_structure_mode == QUEUE)
	{
		temp = NULL;

		while (*stack != NULL && (*stack)->prev != NULL)
		{
			temp = (*stack)->prev;
			temp->next = NULL;
			(*stack)->prev = NULL;
			temp->prev = *stack;
			(*stack)->next = temp;
			*stack = temp;
		}
		data_structure_mode = STACK;
	}
}
