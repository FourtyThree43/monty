#include "monty.h"

/**
 * add_node - adds a new node at the beginning of a stack_t list
 * @stack: pointer to pointer of the top of the stack
 * @n: value to be added to the new node
 *
 * Return: pointer to the newly added node
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
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

	return (new_node);
}
