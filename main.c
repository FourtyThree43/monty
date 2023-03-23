#include "monty.h"

/**
 * main - entry point for the monty program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	nread = getline(&line, &len, file);
	while (nread != -1)
	{
		line_number++;
		if (*line == '\n')
			continue;
		execute_opcode(line, &stack, line_number);
	}
	free(line);
	fclose(file);
	free_stack(stack);
	exit(EXIT_SUCCESS);
}
