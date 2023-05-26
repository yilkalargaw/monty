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
	if (node_new == NULL) {
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node_new->n = nn;
	node_new->prev = NULL;
	node_new->next = (*head);
	((*head) != NULL) ? (*head)->prev = node_new : 0 + 0;
	(*head) = node_new;
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
