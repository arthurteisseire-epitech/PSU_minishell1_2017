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
		if (my_strcmp(builtins[i].name, args[0]) == 0) {
			builtins[i].f(args);
			return (1);
		}
		i++;
	}
	return (0);
}
