#include "monty.h"

/**
 *print_dlistint - prints all the elements of a dlistint_t list.
 *@h: header of the doubly linked list
 *Return: the number of nodes
 */

size_t print_dlistint(const stack_t *h)
{
	unsigned int numNodes = 0;

	if (h == NULL)
		return (numNodes);
	while (h != NULL)
	{
		printf("%i\n", (*h).n);
		h = (*h).next;
		numNodes++;
	}
	return (numNodes);
}

/**
 * add_dnodeint - add node at head of list
 * @head: pointer to list
 * @n: data to add
 * Return: pointer to new node
 */

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);
	(*new_node).n = n;
	(*new_node).prev = NULL;
	(*new_node).next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (new_node);
}

/**
 *free_dlistint -  free a dlistint_t list.
 *@head: head of the list.
 *Return: none
 */

void free_dlistint(stack_t *head)
{
	if (head == NULL)
		return;
	free_dlistint((*head).next);
	free(head);
}

/**
 * delete_head - deletes head node
 * @head: pointer to list
 */

void delete_head(stack_t **head)
{
	stack_t *tmp = *head, *tmp_del = NULL;

	tmp_del = tmp;
	if ((*tmp).next != NULL)
		(*tmp).next->prev = NULL;
	*head = (*tmp).next;
	free(tmp_del);


}

/**
 *dlistint_len - returns the number of elements in a linked dlistint_t list
 *@h: header of the doubly linked list
 *Return: the number of nodes
 */

size_t dlistint_len(const stack_t *h)
{
	unsigned int numNodes = 0;

	if (h == NULL)
		return (numNodes);
	while (h != NULL)
	{
		h = (*h).next;
		numNodes++;
	}
	return (numNodes);
}
