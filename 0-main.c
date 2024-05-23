#include "monty.h"

/**
 * 
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	execute(file);
	fclose(file);
	return 0;
}
