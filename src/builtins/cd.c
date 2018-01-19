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
	if (args == NULL)
		return (1);
	if (args[0] == NULL)
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
	printf("%d\n", i);
	if (i == 1) {
		printf("%s\n", get_var_content("HOME"));
		return (chdir(get_var_content("HOME")));
	}
	else if (i != 2) {
		my_puterror("cd: Too many arguments.");
		return (-1);
	}
	printf("%s\n", get_var_content("PWD"));
	if (my_strcmp(args[1], "-") == 0) {
		return (chdir(get_var_content("OLDPWD")));
	}
	printf("%s\n", get_var_content("HOME"));
	return (chdir(args[1]));
}
