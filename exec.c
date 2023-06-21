#include "main.h"


/**
 * _instruction - .
 * @line: .
 * @line_number: .
 * Return: .
 */
instruction_t _instruction(char *line, unsigned int line_number)
{
	char *token;
	char *arg;
	int n;
	instruction_t instrct;
	instrct.opcode = NULL;
	instrct.f = NULL;

	token = strtok(line, " \t\n");
	if (token == NULL)
	{
		fprintf(stderr, "L%u: empty instruction\n", line_number);
		exit(EXIT_FAILURE);
	}
	instrct.opcode = strdup(token);
	if (strcmp(instrct.opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");
		if (arg == NULL)
		{
			fprintf(stderr, "L%u: push requires an argument\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		arg = NULL;
		token = strtok(NULL, " \t\n");
		if (token != NULL)
		{
			fprintf(stderr, "L%u: instruction %s does not take arguments\n", line_number, instrct.opcode);
			exit(EXIT_FAILURE);
		}
	}
	if (strcmp(instrct.opcode, "push") == 0)
	{
		instrct.f = _push;
		n = atoi(arg);
		_push(&stack_top1, n);
	}
	else if (strcmp(instrct.opcode, "pall") == 0)
	{
		instrct.f = _pall;
		_pall(&stack_top1, line_number);
	}
	else if (strcmp(instrct.opcode, "pint") == 0)
	{
		instrct.f = _pint;
		_pint(&stack_top1, line_number);
	}
	else if (strcmp(instrct.opcode, "pop") == 0)
	{
		instrct.f = _pop;
		_pop(&stack_top1, line_number);
	}
	else if (strcmp(instrct.opcode, "swap") == 0)
	{
		instrct.f = _swap;
		_swap(&stack_top1, line_number);
	}
	else if (strcmp(instrct.opcode, "add") == 0)
	{
		instrct.f = _add;
		_add(&stack_top1, line_number);
	}
	else if (strcmp(instrct.opcode, "nop") == 0)
	{
		instrct.f = nope;
		nope(&stack_top1, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instrct.opcode);
		exit(EXIT_FAILURE);
	}
	return (instrct);
}
