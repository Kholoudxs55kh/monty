#include "monty.h"


/**
 * free_dlistint - .
 * @head: .
 * Return: .
 */
void free_dlistint(stack_t *head)
{
	stack_t *nodeToFree = head;

	while (nodeToFree)
	{
		head = nodeToFree->next;
		free(nodeToFree);
		nodeToFree = head;
	}
}

/**
 * nope - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void nope(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * main - .
 * @argc: .
 * @argv: .
 * Return: .
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		_instruction(line, line_num, fd);
	}

	free(line);
	fclose(fd);
	return (0);
}

