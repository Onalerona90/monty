#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
*/

void push(stack_t **stack, unsigned int line_number)
{
    char *argument;
    int num;
	stack_t *new_node;

    argument = strtok(NULL, " \n");

    if (argument == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    num = atoi(argument);

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;

    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}
