/*
** EPITECH PROJECT, 2024
** is in str
** File description:
** new funcs
*/

int is_in_str(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int are_in_str(char *c, char *str)
{
    for (int i = 0; c[i] != '\0'; i++)
        if (is_in_str(c[i], str))
            return 1;
    return 0;
}
