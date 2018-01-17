/*
** EPITECH PROJECT, 2017
** File Name : get_next_word.c
** File description:
** by Arthur Teisseire
*/

#include "split.h"

char *get_next_word(char **str, char *flags)
{
	int len_word;
	char *word;

	skip_first_flags(str, flags);
	len_word = len_first_word(*str, flags);
	word = malloc(sizeof(char) * (len_word + 1));
	if (word == NULL || len_word == 0)
		return (NULL);
	word[len_word] = '\0';
	my_strncpy(word, *str, len_word);
	(*str) += len_word;
	return (word);
}
