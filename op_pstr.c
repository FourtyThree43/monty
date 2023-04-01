#include "monty.h"

/**
 * op_pstr - prints the string starting at the top of the stack,
 *           followed by a new line
 * @stack: double pointer to the top of the stack.
 * @line_number: current line number of the opcode in the Monty file
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
