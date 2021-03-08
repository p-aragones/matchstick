/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** print_input
*/

#include "utils.h"

void print_player(int line, int matches)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

void print_AI(int line, int matches)
{
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}