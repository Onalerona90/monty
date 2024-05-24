#include "monty.h"

/**
 * main - Entry Point
*/

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    FILE *file;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        line_number++;
        execute(line, line_number, &stack);
    }

    fclose(file);

    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}
