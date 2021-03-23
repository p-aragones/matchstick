/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** get_input
*/

#include "matchstick.h"

int get_line(int n, input_t *input, int *map)
{
    char *ln = NULL;
    int line_num = 0;
    size_t len = 0;
    ssize_t lineSize = 0;

    my_putstr("Line: ");
    lineSize = getline(&ln, &len, stdin);
    if (lineSize == EOF)
        return (-1);
    if (my_str_isnum(ln) == 0 || my_getnbr(ln) < 1 || my_getnbr(ln) > n) {
        my_putstr("Error: this line is out of range\n");
        return (0);
    }
    line_num = my_getnbr(ln);
    free (ln);
    return (line_num);
}

int matches_error(int nbr, char *ln, int *map, int n)
{
    if (my_str_isnum(ln) == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (84);
    }
    if (my_getnbr(ln) < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        return (84);
    }
    if (my_getnbr(ln) > n) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(n);
        my_putstr(" matches per turn\n");
        return (84);
    }
    if (my_getnbr(ln) > nbr) {
        my_putstr("Error: not enough matches on this line\n");
        return (84);
    }
    return (0);
}

int get_matches(int n, input_t *input, int *map)
{
    char *ln = NULL;
    int line_num = 0;
    size_t len = 0;
    ssize_t lineSize = 0;

    if (input->line == 0)
        return (0);
    my_putstr("Matches: ");
    lineSize = getline(&ln, &len, stdin);
    if (lineSize == EOF)
        return (-1);
    if (matches_error(map[input->line - 1], ln, map, n) != 0) {
        return (0);
    }
    line_num = my_getnbr(ln);
    free (ln);
    return (line_num);
}