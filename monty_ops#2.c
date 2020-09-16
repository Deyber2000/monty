#include "monty.h"

/**
 *op_nop - doesn’t do anything.
 *@dlinkedlist: the header of the stack or queue
 *@line_num: this is unused in this function
 *Return: none
 */

void op_nop(stack_t **dlinkedlist, unsigned int line_num)
{
	(void) line_num;
	(void) dlinkedlist;
}

/**
 *op_div - divides the second top element of
 *the stack by the top element of the stack.
 *@dlinkedlist: the header of the stack or queue
 *@line_num: this is unused in this function
 *Return: none
 */

void op_div(stack_t **dlinkedlist, unsigned int line_num)
{
	int a, b;

	if (dlistint_len(*dlinkedlist) < 2)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	if ((*dlinkedlist)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	a = (*dlinkedlist)->n;
	b = (*dlinkedlist)->next->n;
	b /= a;
	delete_head(dlinkedlist);
	(*dlinkedlist)->n = b;
}

/**
 *op_mod - computes the rest of the division of
 *the second top element of the stack by the top element of the stack.
 *@dlinkedlist: the header of the stack or queue
 *@line_num: this is unused in this function
 *Return: none
 */

void op_mod(stack_t **dlinkedlist, unsigned int line_num)
{
	int a, b;

	if (dlistint_len(*dlinkedlist) < 2)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	if ((*dlinkedlist)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	a = (*dlinkedlist)->n;
	b = (*dlinkedlist)->next->n;
	b = b % a;
	delete_head(dlinkedlist);
	(*dlinkedlist)->n = b;
}

/**
 * op_add - adds the top two elements of the stack
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */

void op_add(stack_t **dlinkedlist, unsigned int line_num)
{
	int a, b;

	if (dlistint_len(*dlinkedlist) < 2)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		a = (*dlinkedlist)->n;
		b = (*dlinkedlist)->next->n;
		(*dlinkedlist)->next->n = a + b;
		delete_head(dlinkedlist);
	}
}

/**
 * op_pchar - prints the char at the top of the stack, followed by a new line.
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */

void op_pchar(stack_t **dlinkedlist, unsigned int line_num)
{
	if (*dlinkedlist == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	if ((*dlinkedlist)->n > 127 || ((*dlinkedlist)->n < 0))
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	putchar((char)(*dlinkedlist)->n);
	putchar('\n');
}
