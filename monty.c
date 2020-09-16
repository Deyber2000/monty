#include "monty.h"
/**
 * dlist_destroy - destroy double linked list
 **/
void dlist_destroy(void)
{
	while (gs.size > 0)
		dlist_remove(gs.tail);
	if (gs.fd == NULL)
		fclose(gs.fd);
	if (gs.buffer != NULL)
		free(gs.buffer);
}
/**
 * main - simulation of monty language
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on succes
**/

int main(int ac, char **av)
{
	FILE *FD;
	char *buffer;
	ssize_t glcount;
	ssize_t buffln;

	d_listinit();
	if (ac != 2)
		myexit(-1, NULL);
	FD = open(av[1], "r");
	if (FD  == NULL)
	{
		myexit(-2, av[1]);
	}
	gs.fd = FD;
	while (glcount != -1)
	{
		gs.ln++;
		glcount = getline(&buffer, &buffln, FD);
		if (glcount == -1)
			break;
		gs.buffer = buffer;
		run_opcode(buffer);
	}
	dlist_destroy();
	return (EXIT_SUCCESS);
}
