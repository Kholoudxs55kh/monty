#include "monty.h"
/**
 * _add - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _add(stack_t **stack, unsigned int line_number)
{
        int sum;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        sum = (*stack)->n + (*stack)->next->n;
        _pop(stack, line_number);
        (*stack)->n = sum;
}

/**
 * _sub - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _sub(stack_t **stack, unsigned int line_number)
{
        int sum = 0;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        sum = -((*stack)->n) + (*stack)->next->n;
        _pop(stack, line_number);
        (*stack)->n = sum;
}

/**
 * _div - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _div(stack_t **stack, unsigned int line_number)
{
        int sum;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        sum = (*stack)->next->n / (*stack)->n;
        _pop(stack, line_number);
        (*stack)->n = sum;
}

/**
 * _mul - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _mul(stack_t **stack, unsigned int line_number)
{
        int sum;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        sum = (*stack)->n * (*stack)->next->n;
        _pop(stack, line_number);
        (*stack)->n = sum;
}

/**
 * _mod - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void _mod(stack_t **stack, unsigned int line_number)
{
        int sum;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        sum = (*stack)->next->n % (*stack)->n;
        _pop(stack, line_number);
        (*stack)->n = sum;
}
