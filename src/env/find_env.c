/*
** EPITECH PROJECT, 2017
** File Name : find_env.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "env.h"

char *find_env(char **env, char *var)
{
	int i = 0;

	while (env[i] != NULL) {
		if (begin_match(var, env[i]))
			return (env[i]);
		i++;
	}
	return (NULL);
}

int begin_match(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0') {
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}