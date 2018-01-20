/*
** EPITECH PROJECT, 2017
** File Name : env.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "lk_list.h"
#include "env.h"
#include "split.h"

static control_t *env;

int init_env(void)
{
	int i = 0;
	char **args;

	init_list(env);
	while (environ[i] != NULL) {
		args = split(environ[i], "=");
		if (args) {
			head(args, env);
			free_args(args);
		}
		else
			return (-1);
		i++;
	}
	return (0);
}

int my_setenv(char **args)
{
	int nb_args = count_args(args);

	if (nb_args == 1) {
		my_env();
		return (0);
	} else if (nb_args >= 4) {
		my_puterror("setenv: Too many arguments.");
		return (-1);
	}
	head(args, env);
	return (0);
}

int my_unsetenv(char **args)
{
	if (count_args(args) == 1) {
		my_puterror("unsetenv: Too few arguments.");
		return (-1);
	}
	remove(args[1], env);
	return (0);
}

void my_env(void)
{
	lk_list_t *curr = env->begin;

	while (curr != NULL) {
		my_putstr(curr->name);
		my_putchar('=');
		my_putstr(curr->value);
		my_putchar('\n');
		curr = curr->next;
	}
}
