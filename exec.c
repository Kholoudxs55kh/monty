#include "monty.h"
stack_t *stack_top1 = NULL;

/**
 * _instruction - .
 * @line: .
 * @line_num: .
 * @fd: .
 * Return: .
 */
instruction_t _instruction(char *line, unsigned int line_num, FILE *fd)
{
	char *token = NULL;
	char *arg = NULL;
	bool valid_arg;
	int n = 0, i;
	instruction_t instrct;

	instrct.opcode = NULL;
	instrct.f = NULL;
	token = strtok(line, " \t\n");
	if (token == NULL)
		return (instrct);

	instrct.opcode = strdup(token);
	if (strcmp(instrct.opcode, "push") != 0)
	{
		if (strcmp(instrct.opcode, "pall") == 0)
		{
			instrct.f = _pall;
			_pall(&stack_top1, line_num);
		}
		else if (strcmp(instrct.opcode, "pint") == 0)
		{
			instrct.f = _pint;
			_pint(&stack_top1, line_num);
		}
		else if (strcmp(instrct.opcode, "pop") == 0)
		{
			instrct.f = _pop;
			_pop(&stack_top1, line_num);
		}
		else if (strcmp(instrct.opcode, "swap") == 0)
		{
			instrct.f = _swap;
			_swap(&stack_top1, line_num);
		}
		else if (strcmp(instrct.opcode, "add") == 0)
		{
			instrct.f = _add;
			_add(&stack_top1, line_num);
		}
		else if (strcmp(instrct.opcode, "sub") == 0)
		{
			instrct.f = _sub;
			_sub(&stack_top1, line_num);
		}
		else if (strcmp(instrct.opcode, "div") == 0)
		{
			instrct.f = _div;
			_div(&stack_top1, line_num);
		}
		else if (strcmp(instrct.opcode, "mul") == 0)
		{
			instrct.f = _mul;
			_mul(&stack_top1, line_num);
		}
		else if (strcmp(instrct.opcode, "mod") == 0)
		{
			instrct.f = _mod;
			_mod(&stack_top1, line_num);
		}
		else if (strcmp(instrct.opcode, "nop") == 0)
		{
			instrct.f = nope;
			nope(&stack_top1, line_num);
		}

		else
		{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, instrct.opcode);
		free(instrct.opcode);
		free(line);
		fclose(fd);
		exit(EXIT_FAILURE);
		}

		free(instrct.opcode);
		return (instrct);
	}

	arg = strtok(NULL, " \t\n");
	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free(instrct.opcode);
		free(token);
		free(line);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	/**
	 * to recheck later ?
	 */
	valid_arg = true;
	if (arg[0] == '-')
	{
		i = 1;
		while (arg[i] != '\0')
		{
			if (isdigit(arg[i]))
			{
				n = n * 10 - (arg[i] - '0');
				if (n < INT_MIN)
				{
					valid_arg = false;
					break;
				}
			}
			else
			{
				valid_arg = false;
				break;
			}
			i++;
		}
	}
	else
	{
		i = 0;
		while (arg[i] != '\0')
		{
			if (isdigit(arg[i]))
			{
				n = n * 10 + (arg[i] - '0');
				if (n > 2147483647)
				{
					valid_arg = false;
					break;
				}
			}
			else
			{
				valid_arg = false;
				break;
			}
			i++;
		}
	}
	if (!valid_arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		return (instrct);
	}

	instrct.f = _push;
	_push(&stack_top1, n);

	free(instrct.opcode);
	return (instrct);
}

