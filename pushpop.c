#include "monty.h"

/**
 * monty_push - pushes values to the stack
 * @head: a pointer pointing to the head of the data
 * @nn: the value to be pushed
 *
 * Return: void
 */
void monty_push(stack_t **head, int nn)
{
	stack_t *node_new = (stack_t *)malloc(sizeof(stack_t));

	/* todo: add error handling */
	node_new->n = nn;
	node_new->prev = NULL;
	node_new->next = (*head);
	((*head) != NULL) ? (*head)->prev = node_new : 0 + 0;
	(*head) = node_new;
}

/**
 * monty_pop - pushes values to the stack
 * @head: a pointer pointing to the head of the data
 *
 * Return: the value popped
 */
int monty_pop(stack_t **head)
{
	int res;
	stack_t *tmp = *head;

	res = tmp->n;
	*head = (*head)->next;
	free(tmp);

	return (res);
}

/**
 * monty_pall - prints all values in stack
 * @head: a pointer pointing to the head of the data
 *
 * Return: void
 */
void monty_pall(stack_t **head)
{
	stack_t *tmp;

	for (tmp = *head; tmp != NULL; tmp = tmp->next)
		printf("%d\n", tmp->n);
}

/**
 * monty_pint - func that prints value at head of stack
 * @head: a pointer pointing to the head of the data
 *
 * Return: void
 */
void monty_pint(stack_t **head)
{
	stack_t *tmp = *head;

	if (*head == NULL)
	{
		/* display error code including line number */
		exit(EXIT_FAILURE);
	}

	printf("%d\n", tmp->n);
}
