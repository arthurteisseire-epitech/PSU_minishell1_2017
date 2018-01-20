/*
** EPITECH PROJECT, 2017
** File Name : get_name_content.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"

void skip_name(char **name)
{
	while (**name != '=')
		(*name)++;
	(*name)++;
}

char *get_value(char *name)
{
	int len_name = my_strlen(name);
	int i = 0;
	int j = 0;

	while (my_strncmp(name, environ[i], len_name) != 0 && environ[i])
		i++;
	while (environ[i][j] != '=')
		j++;
	j++;
	return (&(environ[i][j]));
}
