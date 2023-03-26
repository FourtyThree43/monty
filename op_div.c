#include "monty.h"

/**
 * op_div - divides the second top element of the stack by the top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the file
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = temp->n;
	b = temp->next->n;
	b /= a;

	*stack = temp->next;
	free(temp);
}
