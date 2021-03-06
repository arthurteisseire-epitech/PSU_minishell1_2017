/*
** EPITECH PROJECT, 2017
** File Name : split.c
** File description:
** by Arthur Teisseire
*/

#include "split.h"

char **split(char *str, char *flags)
{
	int nb_words = count_words(str, flags);
	char **res = malloc(sizeof(char *) * (nb_words + 1));
	int i = 0;

	res[nb_words] = NULL;
	while (i < nb_words) {
		res[i] = get_next_word(&str, flags);
		i++;
	}
	return (res);
}
