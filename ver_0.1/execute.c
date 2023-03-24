#include "monty.h"

/**
 * execute_opcode - execute an opcode
 * @line: the line containing the opcode
 * @stack: pointer to the stack
 * @line_number: the current line number
 *
 * Return: no return
 */
void execute_opcode(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	unsigned int i = 0;
	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	/* Split the line into opcode and argument */
	opcode = strtok(line, " \t\n");
	/* Ignore blank lines */
	if (opcode == NULL)
		return;
	/* Find the opcode in the list of supported opcodes */
	for (i = 0; operations[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, operations[i].opcode) == 0)
		{
			operations[i].f(stack, line_number);
			return;
		}
	}
	if (operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free(line);
		exit(EXIT_FAILURE);
	}
}
