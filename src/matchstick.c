/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "matchstick.h"

int handle_input(input_t *input, int n, int *map, int max)
{
    input->line = get_line(n, input, map);
    if (input->line == EOF)
        return (84);
    input->matches = get_matches(max, input, map);
    if (input->matches == EOF)
        return (84);
    if (input->line == 0 || input->matches == 0) {
        if (handle_input(input, n, map, max) == 84)
            return (84);
    }
    return (0);
}

int main_loop(int *map, int n, int max)
{
    input_t *input = malloc(sizeof(input_t));
    int total = n * n;
    int win_status = 0;

    init_input(input, n);
    if (!input)
        return (84);
    while (win_status != 1 && win_status != 2) {
        print_map(map, n);
        my_putstr("\nYour turn:\n");
        if (handle_input(input, n, map, max) == 84)
            return (0);
        print_player(input->line, input->matches, &map, &total);
        print_map(map, n);
        win_status = ai_turn(&map, max, input, &total);
    }
    if (win_status == 1)
        print_map(map, n);
    free (input);
    return (win_status);
}

int matchstick(int n, int max)
{
    int *map = NULL;
    int status = 0;

    if (n <= 1 || n >= 100 || max <= 0)
        return (84);
    map = create_map(n);
    if (!map)
        return (84);
    status = main_loop(map, n, max);
    if (status == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    free (map);
    return (status);
}