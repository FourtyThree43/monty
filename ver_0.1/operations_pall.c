#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the top/head of the stack
 * @line_number: line number in the Monty file
 *
 * Return: none
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (tmp == NULL)
		return;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
