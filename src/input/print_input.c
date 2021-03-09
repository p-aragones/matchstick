/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** print_input
*/

#include "utils.h"

void print_player(int line, int matches, int **map, int *total)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    *total -= matches;
    (*map)[line - 1] -= matches;
}

void print_ai(int line, int matches)
{
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}