/*
** EPITECH PROJECT, 2017
** File Name : count_words.c
** File description:
** by Arthur Teisseire
*/

#include "split.h"

int count_words(char *str, char *flags)
{
	int nb_words = 0;

	while (*str != '\0') {
		while (in_str(*str, flags))
			str++;
		if (*str != '\0')
			nb_words++;
		while (*str != '\0' && !in_str(*str, flags))
			str++;
	}
	return (nb_words);
}
