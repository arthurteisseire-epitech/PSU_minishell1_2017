/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "get_next_line.h"

int main(int ac, char **av, char **env)
{
	int status;

	if (ac != 1) {
		my_puterror(av[0]);
		my_puterror(": The program must take two and only two argument\n");
		return (84);
	}
	status = mysh(env);
	if (status == 0) {
		my_puterror("An error occured during the program creation\n");
		return (84);
	}
	return (0);
}
