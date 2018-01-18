/*
** EPITECH PROJECT, 2017
** File Name : get_var_content.c
** File description:
** by Arthur Teisseire
*/

void skip_path_var(char **var)
{
        while (**var != '=')
                (*var)++;
        (*var)++;
}

char *get_var_content(char *var)
{
	skip_path_var(&var);
	return (var);
}
