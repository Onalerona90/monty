#include "monty.h"

/**
 * 
*/

void push(stack_t **stack, unsigned int line_number, char *arg)
{
	if (arg == NULL || (!isdigit(*arg) && *arg != '-' && !isdigit(arg[1])))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arg);
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
