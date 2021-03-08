/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** get_input
*/

#include "matchstick.h"

int get_line(int n)
{
    char *line = NULL;
    int line_num = 0;
    size_t len = 0;
    ssize_t lineSize = 0;

    my_putstr("Line: ");
    lineSize = getline(&line, &len, stdin);
    if (lineSize == EOF)
        return (-1);
    if (my_str_isnum(line) == 0 ||
    my_getnbr(line) < 1 || my_getnbr(line) > n) {
        my_putstr("Error: this line is out of range\n");
        get_line(n);
    }
    line_num = my_getnbr(line);
    free (line);
    return (line_num);
}

int get_matches(int n)
{
    char *line = NULL;
    int line_num = 0;
    size_t len = 0;
    ssize_t lineSize = 0;

    my_putstr("Matches: ");
    lineSize = getline(&line, &len, stdin);
    if (lineSize == EOF)
        return (-1);
    if (my_str_isnum(line) == 0 ||
    my_getnbr(line) < 1 || my_getnbr(line) > n) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(n);
        my_putstr(" matches per turn\n");
        get_line(n);
    }
    line_num = my_getnbr(line);
    free (line);
    return (line_num);
}