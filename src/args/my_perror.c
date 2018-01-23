/*
** EPITECH PROJECT, 2017
** File Name : my_perror.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "my_perror.h"

void my_perror(char *str)
{
	my_putstr(str);
	my_putstr(": ");
	my_putstr(strerror(errno));
	my_putstr(".\n");
}
