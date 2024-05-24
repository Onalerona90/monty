#include "monty.h"

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", div_op},
	{"mul", mul},
	{"mod", mod},
	{NULL, NULL}
};
