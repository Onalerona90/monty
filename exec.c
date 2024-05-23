#include "monty.h"

/**
 * 
*/

void execute(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		char *command = strtok(line, " \n\t");
		if (command == NULL || command[0] == '#')
			continue;

		if (strcmp(command, "push") == 0)
		{
			char *arg = strtok(NULL, " \n\t");
			push(&stack, line_number, arg);
		}
		else
		{
			int i = 0;
			while (instructions[i].opcode != NULL)
			{
				if (strcmp(command, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, line_number);
					break;
				}
				i++;
			}
			if (instructions[i].opcode == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
				free(line);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(line);
	free_stack(stack);
}
