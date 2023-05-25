#include "monty.h"
#include <stdio.h>

/**
 * valid_1arg_command - checks if command is a valid noarg
 * @opcode: the command to be checked
 *
 * Return: true or false
 */
int valid_1arg_command(char *opcode)
{
	char *command_list[] = {"push"};
	int i;

	for (i = 0; i < 1; i++)
	{
		if (strcmp(opcode, command_list[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * valid_noarg_command - checks if command is a valid noarg
 * @opcode: the command to be checked
 *
 * Return: true or false
 */
int valid_noarg_command(char *opcode)
{
	char *command_list[] = {"pop", "pall", "pint",
							"swap", "add"};
	int i;

	for (i = 0; i < 5; i++)
	{
		if (strcmp(opcode, command_list[i]) == 0)
			return (1);
	}
	return (0);
}


/**
 * main - the main exec loop for the shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: status code
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	char line[256], *opcode, *operand;
	unsigned int linum = 0;
	stack_t *mystack = NULL;

	if (argc != 2)
	{
		/* printf("Usage: %s <filename>\n", argv[0]); */
		return (1);
	}

	if (file == NULL)
	{
		/* printf("Error: Can't open file %s\n", argv[1]); */
		return (1);
	}

	while (fgets(line, sizeof(line), file))
	{
		opcode = strtok(line, " \t\n");
		if (opcode != NULL && valid_1arg_command(opcode) != 0)
		{
			/* printf("## line %u, opcode: %s ", linum, opcode); */
			RUN_MONTY_ONE_OPERAND();
		}
		else if (valid_noarg_command(opcode) != 0)
		{
			/* printf("## line %u, opcode: %s\n", linum, opcode); */
			RUN_MONTY_NO_OPERAND(opcode);
		}
		linum++;
	}

	free_list(mystack);

	fclose(file);
	return (0);
}
