/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "matchstick.h"

void handle_input(input_t *input, int n, int *map, int max)
{
    input->line = get_line(n, input, map);
    input->matches = get_matches(max, input, map);
    if (input->line == 0 || input->matches == 0)
        handle_input(input, n, map, max);
}

int main_loop(int *map, int n, int max)
{
    input_t *input = malloc(sizeof(input_t));
    int total = n * n;
    int win_status = 0;

    init_input(input);
    if (!input)
        return (84);
    while (total > 0) {
        print_map(map, n);
        my_putstr("\nYour turn:\n");
        handle_input(input, n, map, max);
        print_player(input->line, input->matches, &map, &total);
        print_map(map, n);
        win_status = ai_turn(&map, max, input, &total);
        if (win_status == 1) {
            print_map(map, n);
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (win_status);
        } else if (win_status == 2)
            return (win_status);
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