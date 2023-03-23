#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: pointer to the top/head of the stack
 * @line_number: line number in the Monty file.
 *
 * Return: none
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *arg;
	int n;

	arg = strtok(NULL, " \t\n");
	if (arg == NULL || ((!isdigit(*arg) && *arg != '-') && strlen(arg) > 1))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
