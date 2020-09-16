#include "monty.h"

/**
 * op_sub - subtracts the top two elements of the stack
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */

void op_sub(stack_t **dlinkedlist, unsigned int line_num)
{
	int a, b;

	if (dlistint_len(*dlinkedlist) < 2)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		a = (*dlinkedlist)->n;
		b = (*dlinkedlist)->next->n;
		(*dlinkedlist)->next->n = b - a;
		delete_head(dlinkedlist);
	}
}

/**
 * op_mul - multiply the top two elements of the stack
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */

void op_mul(stack_t **dlinkedlist, unsigned int line_num)
{
	int a, b;

	if (dlistint_len(*dlinkedlist) < 2)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		a = (*dlinkedlist)->n;
		b = (*dlinkedlist)->next->n;
		(*dlinkedlist)->next->n = a * b;
		delete_head(dlinkedlist);
	}
}

/**
 * op_stack - sets format to stack (LIFO)
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */

void op_stack(stack_t **dlinkedlist, unsigned int line_num)
{
	(void) line_num;
	(void) dlinkedlist;
	carrier.state = 0;
}

/**
 * op_queue - sets format to queue (FIFO)
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */

void op_queue(stack_t **dlinkedlist, unsigned int line_num)
{
	(void) line_num;
	(void) dlinkedlist;
	carrier.state = 1;
}

/**
 * op_pstr - multiply the top two elements of the stack
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */

void op_pstr(stack_t **dlinkedlist, unsigned int line_num)
{
	stack_t *temp = NULL;

	line_num = line_num;
	temp = *dlinkedlist;

	while (temp != NULL && temp->n != 0)
	{
		if (temp->n > 0 && temp->n <= 127)
		{
			putchar(temp->n);
		}
		else
			break;
		temp = temp->next;
	}
	putchar('\n');
}
