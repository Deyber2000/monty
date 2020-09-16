#include "monty.h"

/**
 * op_rotl - subtracts the top two elements of the stack
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */

void op_rotl(stack_t **dlinkedlist, unsigned int line_num)
{
	stack_t *tmp = *dlinkedlist;

	(void) line_num;
	if (*dlinkedlist == NULL)
		return;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *dlinkedlist;
	(*dlinkedlist)->prev = tmp;
	tmp = (*dlinkedlist)->next;
	(*dlinkedlist)->next = NULL;
	*dlinkedlist = tmp;
	(*dlinkedlist)->prev = NULL;
}

/**
 * op_rotr - subtracts the top two elements of the stack
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */

void op_rotr(stack_t **dlinkedlist, unsigned int line_num)
{
	stack_t *tmp = *dlinkedlist;

	(void) line_num;

	if (tmp == NULL || tmp->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = (*dlinkedlist);
	*dlinkedlist = tmp;
}
