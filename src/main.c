/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "get_next_line.h"
#include "lk_list.h"

control_t *env;

int main(int ac, char **av)
{
	int status;

	if (ac != 1) {
		my_puterror(av[0]);
		my_puterror(": The program must take one argument\n");
		return (84);
	}
	status = mysh();
	if (status == 0) {
		my_puterror("An error occured\n");
		return (84);
	}
	return (0);
}
