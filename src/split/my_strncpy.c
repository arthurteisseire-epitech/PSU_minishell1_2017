/*
** EPITECH PROJECT, 2017
** Day06
** File description:
** Arthur Teisseire
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
