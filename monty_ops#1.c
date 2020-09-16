#include "monty.h"


/**
 *op_pall -  prints all the values on the stack,
 *starting from the top of the stack or queue.
 *@dlinkedlist: the header of the stack or queue
 *@line_num: this is unused in this function
 *Return: none
 */

void op_pall(stack_t **dlinkedlist, unsigned int line_num)
{
	(void) line_num;
	print_dlistint(*dlinkedlist);
}

/**
 * op_push - pushes data to stack
 * @dlinkedlist: pointer to list
 * @line_num: line number of command
 */

void op_push(stack_t **dlinkedlist, unsigned int line_num)
{
	/* Check if line_num is an integer */
	(void) line_num;
	if (carrier.state == 0)
		add_dnodeint(dlinkedlist, carrier.data);
	else
		add_dnodeint_end(dlinkedlist, carrier.data);
}

/**
 *op_pint - prints the value at the top of the stack, followed by a new line
 * @dlinkedlist: pointer to list
 * @line_num: line number of command
 */

void op_pint(stack_t **dlinkedlist, unsigned int line_num)
{
	if (*dlinkedlist == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);

		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*dlinkedlist)->n);
}

/**
 * op_pop - removes an item from a stack
 * @dlinkedlist: pointer to a list
 * @line_num: line number of op command
 */

void op_pop(stack_t **dlinkedlist, unsigned int line_num)
{

	if (*dlinkedlist == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);

		exit(EXIT_FAILURE);
	}
	else
	{
		delete_head(dlinkedlist);
	}
}

/**
 * op_swap -  swaps the top two elements of the stack.
 * @dlinkedlist: pointer to a list
 * @line_num: line number of op command
 */

void op_swap(stack_t **dlinkedlist, unsigned int line_num)
{
	int a, b;

	if (dlistint_len(*dlinkedlist) < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	a = (*dlinkedlist)->n;
	b = (*dlinkedlist)->next->n;
	(*dlinkedlist)->n = b;
	(*dlinkedlist)->next->n = a;
}
