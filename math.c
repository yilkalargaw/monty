#include "monty.h"

/**
 * monty_add - adds the top two elements of the stack
 * @head: a pointer pointing to the head of the data
 *
 * Return: void
 */
void monty_add(stack_t **head)
{
	stack_t *tmp = *head;

	if (tmp == NULL || tmp->next == NULL)
	{
		/* todo print error message along with line number */
		exit(EXIT_FAILURE);
	}

	tmp->next->n += tmp->n;
	monty_pop(head);
}

/**
 * monty_sub - subtracts the top from the second
 * @head: a pointer pointing to the head of the data
 *
 * Return: void
 */
void monty_sub(stack_t **head)
{
	stack_t *tmp = *head;

	if (tmp == NULL || tmp->next == NULL)
	{
		/* todo print error message along with line number */
		exit(EXIT_FAILURE);
	}

	tmp->next->n -= (*head)->n;
	monty_pop(head);
}

/**
 * monty_div - divides second top by top
 * @head: a pointer pointing to the head of the data
 *
 * Return: void
 */
void monty_div(stack_t **head)
{
	stack_t *tmp = *head;

	if (tmp == NULL || tmp->next == NULL)
	{
		/* todo print error message along with line number */
		exit(EXIT_FAILURE);
	}

	tmp->next->n /= (*head)->n;
	monty_pop(head);
}

/**
 * monty_mul - multiplies the top two elements of the stack
 * @head: a pointer pointing to the head of the data
 *
 * Return: void
 */
void monty_mul(stack_t **head)
{
	stack_t *tmp = *head;

	if (tmp == NULL || tmp->next == NULL)
	{
		/* todo print error message along with line number */
		exit(EXIT_FAILURE);
	}

	tmp->next->n *= tmp->n;
	monty_pop(head);
}


/**
 * monty_mod - divides second top by top puts remainder
 * @head: a pointer pointing to the head of the data
 *
 * Return: void
 */
void monty_mod(stack_t **head)
{
	stack_t *tmp = *head;

	if (tmp == NULL || tmp->next == NULL)
	{
		/* todo print error message along with line number */
		exit(EXIT_FAILURE);
	}

	tmp->next->n %= (*head)->n;
	monty_pop(head);
}
