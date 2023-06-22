#include "monty.h"
file_close f_close = {NULL};

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
 * free_st - .
 * @head: .
 * Return: .
 */
void free_st(stack_t **head)
{
	stack_t *temp = NULL;

	if (!head)
		return;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
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
	f_close.file = fd;
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fd)
	{
		while (getline(&line, &len, fd) != -1)
		{
			line_num++;
			f_close.line = line;
			_instruction(line, line_num, fd);
		}
		free(f_close.line);
		fclose(fd);
	}
	free_st(f_close.stack);
	return (0);
}

