/*
** EPITECH PROJECT, 2017
** File Name : env.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "env.h"
#include "split.h"
#include "lk_list.h"

int init_env(void)
{
	int i = 0;
	char **args;

	init_list();
	while (environ[i] != NULL) {
		args = split(environ[i], "=");
		if (args) {
			head(args);
			free_args(args);
		} else
			return (-1);
		i++;
	}
	return (0);
}

int my_setenv(char **args)
{
	int nb_args = count_args(args);

	if (nb_args == 1) {
		my_env(args);
		return (0);
	} else if (nb_args >= 4) {
		my_puterror("setenv: Too many arguments.\n");
		return (-1);
	}
	head(args);
	return (0);
}

int my_unsetenv(char **args)
{
	if (count_args(args) == 1) {
		my_puterror("unsetenv: Too few arguments.\n");
		return (-1);
	}
	delete_node(args[1]);
	return (0);
}

int my_env(char **args)
{
	lk_list_t *curr = env->begin;

	if (args[1]) {
		perror(args[1]);
		return (-1);
	}
	while (curr != NULL) {
		my_putstr(curr->name);
		my_putchar('=');
		my_putstr(curr->value);
		my_putchar('\n');
		curr = curr->next;
	}
	return (0);
}


