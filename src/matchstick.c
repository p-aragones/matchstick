/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "matchstick.h"

void handle_input(input_t *input, int n, int *map)
{
    input->line = get_line(n, input, map);
    input->matches = get_matches(n, input, map);
    if (input->line == 0 || input->matches == 0)
        handle_input(input, n, map);
}

int main_loop(int *map, int n, int max)
{
    input_t *input = malloc(sizeof(input_t));
    int total = n * n;

    init_input(input);
    if (!input)
        return (84);
    while (total > 0) {
        print_map(map, n);
        my_putstr("\nYour turn:\n");
        handle_input(input, n, map);
        print_player(input->line, input->matches, &map, &total);
        print_map(map, n);
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