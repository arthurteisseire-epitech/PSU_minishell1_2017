/*
** EPITECH PROJECT, 2017
** File Name : free_args.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"

void free_args(char **args)
{
	int i = 0;

	while (args[i]) {
		free(args[i]);
		i++;
	}
	free(args);
}
