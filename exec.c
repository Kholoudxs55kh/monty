#include "monty.h"


/**
 * _instruction - .
 * @line: .
 * @line_number: .
 * Return: .
 */
instruction_t _instruction(char *line, unsigned int line_number, FILE *fd)
{
	char *token;
	char *arg;
	bool valid_arg;
	int n;
	instruction_t instrct;

	instrct.opcode = NULL;
	instrct.f = NULL;
	token = strtok(line, " \t\n");
	if (token == NULL)
		return (instrct);
	instrct.opcode = strdup(token);
	if (strcmp(instrct.opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");
		if (arg == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_dlistint(stack_top1);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		arg = NULL;
		token = strtok(NULL, " \t\n");
		if (token != NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
	if (strcmp(instrct.opcode, "push") == 0)
	{
		instrct.f = _push;
		n = atoi(arg);
		valid_arg = (n != 0 || strcmp(arg, "0") == 0);
		if (!valid_arg)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			fclose(fd);
			free_dlistint(stack_top1);
			exit(EXIT_FAILURE);
		}
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
	else if (strcmp(instrct.opcode, "sub") == 0)
	{
		instrct.f = _sub;
		_sub(&stack_top1, line_number);
	}
	else if (strcmp(instrct.opcode, "div") == 0)
	{
		instrct.f = _div;
		_div(&stack_top1, line_number);
	}
	else if (strcmp(instrct.opcode, "mul") == 0)
	{
		instrct.f = _mul;
		_mul(&stack_top1, line_number);
	}
	else if (strcmp(instrct.opcode, "mod") == 0)
	{
		instrct.f = _mod;
		_mod(&stack_top1, line_number);
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
	free(instrct.opcode);
	return (instrct);
}
