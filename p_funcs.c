#include "monty.h"

/**
 * _pchar - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int Chr;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_st(f_close.stack);
		exit(EXIT_FAILURE);
	}
	Chr = (*stack)->n;
	if (Chr < 0 || Chr > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_st(f_close.stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", Chr);
}
/**
 * _pstr - .
 * @stack: .
 * @line_number: .
 * Return:.
 */
void _pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	char buffer[100];
	int i = 0;
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}


	while (current != NULL && current->n != 0
			&& current->n >= 0 && current->n <= 127)
	{
		buffer[i++] = current->n;
		current = current->next;
	}

	buffer[i] = '\0';
	printf("%s\n", buffer);
}
