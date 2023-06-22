#include "monty.h"

/**
 * _push - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t **head;
	head = f_close.stack;
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint(*stack);
		free_dlistint(new_node);
		free(f_close.line);
		free(stack_top1);
		fclose(f_close.file);
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		new_node->next->prev = new_node;
	*head = new_node;
}

/**
 * _pall - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * _pint - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);

		free(f_close.line);
		fclose(f_close.file);
		free_st(f_close.stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _pop - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_st(f_close.stack);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * _swap - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *sec = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_st(f_close.stack);
		exit(EXIT_FAILURE);
	}
	first->next = sec->next;
	first->prev = sec;
	sec->next = first;
	sec->prev = NULL;
	*stack = sec;
}

