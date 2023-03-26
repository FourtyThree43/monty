#include "monty.h"

/**
 * op_sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the file
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	a = (*stack)->n;
	b = (*stack)->next->n;
	b -= a;
	*stack = temp->next;
	free(temp);
}
