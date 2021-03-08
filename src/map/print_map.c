/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** print_map
*/

#include "utils.h"

void print_end(int n, int max)
{
    while (n < max + 1) {
        my_putchar(' ');
        n++;
    }
    my_putchar('*');
}

void print_top_bottom(int n)
{
    int i = 0;

    while (i < n + 1) {
        my_putchar('*');
        i++;
    }
    my_putchar('\n');
}

void put_stick(int *k, int i, int *space)
{
    while (*k < i) {
        my_putchar('|');
        *space += 1;
        *k += 1;
    }
}

void print_map(int *map, int n)
{
    int i = 0;
    int space = 2;
    int k = 0;

    print_top_bottom(n * 2);
    while (i < n) {
        space = 2;
        my_putchar('*');
        while (space <= n - i) {
            my_putstr(" ");
            space++;
        }
        put_stick(&k, map[i], &space);
        print_end(space, n * 2);
        my_putchar('\n');
        i++;
        k = 0;
    }
    print_top_bottom(n * 2);
}