/*
** EPITECH PROJECT, 2017
** File Name : cd.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"

static int is_null(char **args)
{
	if (!args)
		return (1);
	if (!args[0])
		return (1);
	return (0);
}

int cd(char **args)
{
	int i = 0;

	if (is_null(args))
		return (-1);
	while (args[i] != NULL)
		i++;
	if (i == 1)
		return (chdir(get_var_content("HOME")));
	else if (i != 2) {
		my_puterror("cd: Too many arguments.");
		return (-1);
	}
	if (my_strcmp(args[1], "-"))
		return (chdir(get_var_content("OLDPWD")));
	return (chdir(args[1]));
}
