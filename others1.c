#include "monty.h"

/**
 * _isdigit -  short description
 * @c: input character
 * Return: 1 if digit 0 if non-digit
 */
int _isdigit(int c)
{
	if ('0' <= c && '9' >= c)
		return (1);
	else
		return (0);
}

/**
 * _consists_of_digits -  short description
 * @str: input character array
 * Return: 1 if digit 0 if non-digit
 */
int _consists_of_digits(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (!_isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * free_list - function that frees a doubly linked list
 * @head: a pointer pointing to the head of the data
 *
 * Return void
 */
void free_list(stack_t *head)
{
	stack_t *cpy;

	for (; head != NULL; head = head->next)
	{
		cpy = head;
		free(cpy);
	}
}
