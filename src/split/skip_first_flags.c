/*
** EPITECH PROJECT, 2017
** File Name : skip_first_flags.c
** File description:
** by Arthur Teisseire
*/

#include "split.h"

int skip_first_flags(char **str, char *flags)
{
	int i = 0;

	while (in_str((*str)[i], flags))
		i++;
	*str += i;
	return (i);
}
