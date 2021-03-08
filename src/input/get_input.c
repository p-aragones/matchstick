/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** get_input
*/

#include "matchstick.h"

int get_line(int n, input_t *input)
{
    char *l = NULL;
    int line_num = 0;
    size_t len = 0;
    ssize_t lineSize = 0;

    my_putstr("Line: ");
    lineSize = getline(&l, &len, stdin);
    if (lineSize == EOF)
        return (-1);
    if (my_str_isnum(l) == 0 || my_getnbr(l) < 1 || my_getnbr(l) > n) {
        my_putstr("Error: this line is out of range\n");
        return (0);
    }
    line_num = my_getnbr(l);
    free (l);
    return (line_num);
}

int get_matches(int n, input_t *input)
{
    char *l = NULL;
    int line_num = 0;
    size_t len = 0;
    ssize_t lineSize = 0;

    if (input->line == 0)
        return (0);
    my_putstr("Matches: ");
    lineSize = getline(&l, &len, stdin);
    if (lineSize == EOF)
        return (-1);
    if (my_str_isnum(l) == 0 || my_getnbr(l) < 1 || my_getnbr(l) > n) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(n);
        my_putstr(" matches per turn\n");
        return (0);
    }
    line_num = my_getnbr(l);
    free (l);
    return (line_num);
}