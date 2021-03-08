/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "matchstick.h"

int main_loop(int *map, int n, int max)
{
    int total = n;
    int line = 0;
    int matches = 0;

    while (total > 0) {
        print_map(map, n);
        my_putstr("\nYour turn:\n");
        line = get_line(n);
        matches = get_matches(n);
        if (line == -1 || matches == -1)
            return (84);
        print_player(line, matches);
        my_putstr("\nAI's turn...\n");
    }
}

int matchstick(int n, int max)
{
    int *map;
    int error = 0;

    if (n <= 1 || n >= 100 || max <= 0)
        return (84);
    map = create_map(n);
    if (!map)
        return (84);
    error = main_loop(map, n, max);
    free (map);
    return (error);
}