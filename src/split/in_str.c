/*
** EPITECH PROJECT, 2017
** File Name : in_str.c
** File description:
** by Arthur Teisseire
*/

#include "split.h"

int in_str(char c, char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
