#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


#define MAX_LENGTH 2048
#define MAX_LINE 2048

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* struct stack_t *head = NULL; */

void monty_push(stack_t **head, int nn);
void monty_pall(stack_t **head);
void monty_pint(stack_t **head);
int monty_pop(stack_t **head);
void monty_swap(stack_t **head);
void monty_add(stack_t **head);
int _isdigit(int c);
int _consists_of_digits(char *str);
void free_list(stack_t *head);
int valid_1arg_command(char *opcode);
int valid_noarg_command(char *opcode);

#define RUN_MONTY_NO_OPERAND(opcode) \
	do { \
		if (strcmp(opcode, "pall") == 0) \
			monty_pall(&mystack); \
		else if (strcmp(opcode, "pint") == 0) \
			monty_pint(&mystack); \
		else if (strcmp(opcode, "pint") == 0) \
			monty_pint(&mystack); \
		else if (strcmp(opcode, "swap") == 0) \
			monty_swap(&mystack); \
		else if (strcmp(opcode, "pop") == 0) \
			monty_pop(&mystack); \
		else if (strcmp(opcode, "add") == 0) \
			monty_add(&mystack); \
	} while (0)

#define RUN_MONTY_ONE_OPERAND() \
	do { \
		operand = strtok(NULL, " \t\n");		\
		if (operand != NULL) \
		{ \
			if (atoi(operand) != 0 || _consists_of_digits(operand) != 0) \
				monty_push(&mystack, atoi(operand)); \
			else \
			{ \
				fprintf(stderr, "L%u: usage: push integer", linum); \
				exit(EXIT_FAILURE); \
			} \
		} \
	} while (0)
#endif /* MONTY_H  */
