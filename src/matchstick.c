/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "matchstick.h"

void handle_input(input_t *input, int n)
{
    input->line = get_line(n, input);
    input->matches = get_matches(n, input);
    if (input->line == 0 || input->matches == 0)
        handle_input(input, n);
}

int main_loop(int *map, int n, int max)
{
    input_t *input = malloc(sizeof(input_t));
    int total = n * n;

    if (!input)
        return (84);
    while (total > 0) {
        print_map(map, n);
        my_putstr("\nYour turn:\n");
        handle_input(input, n);
        print_player(input->line, input->matches, &map, &total);
        my_putstr("\nAI's turn...\n");
        init_input(input);
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