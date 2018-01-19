/*
** EPITECH PROJECT, 2017
** File Name : get_var_content.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"

void skip_path_var(char **var)
{
        while (**var != '=')
                (*var)++;
        (*var)++;
}

char *get_var_content(char *var)
{
	int len_var = my_strlen(var);
	int i = 0;
	int j = 0;

	printf("var: %s\n", var);
	while (my_strncmp(var, environ[i], 2) != 0 && environ[i]) {
		printf("%s\n", environ[i]);
		i++;
	}
	printf("environ fin : %s\n", environ[i]);
	printf("index env var: %d\n", i);
	while (environ[i][j] != '=')
		j++;
	j++;
	return (&(environ[i][j]));
}
