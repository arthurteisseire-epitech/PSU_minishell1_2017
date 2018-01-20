/*
** EPITECH PROJECT, 2017
** File Name : count_args.c
** File description:
** by Arthur Teisseire
*/

int count_args(char **args)
{
	int i = 0;

	while (args[i])
		i++;
	return (i);
}
