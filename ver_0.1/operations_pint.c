#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the top/head of the stack
 * @line_number: line number in the Monty file
 *
 * Return: none
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
