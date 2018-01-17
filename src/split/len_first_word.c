/*
** EPITECH PROJECT, 2017
** File Name : len_first_word.c
** File description:
** by Arthur Teisseire
*/

#include "split.h"

int len_first_word(char *str, char *flags)
{
	int i = 0;

	while (str[i] != '\0' && !in_str(str[i], flags))
		i++;
	return (i);
}
