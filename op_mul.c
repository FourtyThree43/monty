#include "monty.h"

/**
 * op_mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the file
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	a = temp->n;
	b = temp->next->n;
	b *= a;

	*stack = temp->next;
	free(temp);
}
