/*
** EPITECH PROJECT, 2017
** File Name : exec_builtins.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "builtins.h"

static const builtins_t builtins[NB_BUILTINS] = {
	{"cd", cd}
};

int exec_builtins(char **args)
{
	int i = 0;

	while (i < NB_BUILTINS) {
		printf("builtins_name: '%s', args[0]: '%s'\n", builtins[i].name, args[0]);
		if (my_strcmp(builtins[i].name, args[0]) == 0) {
			builtins[i].f(args);
			printf("In cd\n");
			return (1);
		}
		i++;
	}
	return (0);
}
