/*
** EPITECH PROJECT, 2017
** File Name : split.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "tools.h"

char **split(char *str, char flag)
{
	int nb_words = count_words(str, flag);
	char **res = malloc(sizeof(char *) * (nb_words + 1));
	int i = 0;

	res[nb_words] = NULL;
	while (i < nb_words) {
		res[i] = get_next_word(&str, flag);
		i++;
	}
	return (res);
}

char *get_next_word(char **str, char flag)
{
	int len_word;
	char *word;

	skip_first_flags(str, flag);
	len_word = len_first_word(*str, flag);
	word = malloc(sizeof(char) * (len_word + 1));
	if (word == NULL || len_word == 0)
		return (NULL);
	word[len_word] = '\0';
	my_strncpy(word, *str, len_word);
	(*str) += len_word;
	return (word);
}

int skip_first_flags(char **str, char flag)
{
	int i = 0;

	while ((*str)[i] == flag)
		i++;
	*str += i;
	return (i);
}

int len_first_word(char *str, char flag)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != flag)
		i++;
	return (i);
}

int count_words(char *str, char flag)
{
	int nb_words = 0;

	while (*str != '\0') {
		while (*str == flag) {
			str++;
		}
		if (*str != '\0')
			nb_words++;
		while (*str != '\0' && *str != flag) {
			str++;
		}
	}
	return (nb_words);
}
