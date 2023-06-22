#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

extern stack_t *stack_top1;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct fileclose - .
 * @file: .
 * @line: .
 * @stack: .
 *
 * Description: to help close the file
 */
typedef struct fileclose
{
	FILE *file;
	char *line;
	stack_t **stack;
} file_close;
extern file_close f_close;

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void nope(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
instruction_t _instruction(char *line, unsigned int line_num, FILE *fd);
void free_dlistint(stack_t *head);
void func_2(instruction_t *instrct, char *arg, FILE *fd, char *token, char *line, unsigned int line_number);
void free_ex(char *arg, char *token,instruction_t *instrct, char *line, FILE *fd);
void func_(instruction_t *instrct, char *arg, FILE *fd, char *token, char *line, unsigned int line_number);
void free_stack(stack_t **head);
void free_st(stack_t **head);
void _pchar(stack_t **stack, unsigned int line_number);

void _pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number);
#endif
