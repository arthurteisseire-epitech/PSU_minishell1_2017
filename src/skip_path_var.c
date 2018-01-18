/*
** EPITECH PROJECT, 2017
** File Name : skip_path_var.c
** File description:
** by Arthur Teisseire
*/

void skip_path_var(char **var)
{
        while (**var != '=')
                (*var)++;
        (*var)++;
}
