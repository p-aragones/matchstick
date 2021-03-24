/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-matchstick-pol.aragones
** File description:
** remove_match
*/

#include "matchstick.h"

void match_removed(int remove, int *total, int **map, int i)
{
    (*map)[i] -= remove;
    *total -= remove;
    print_ai(i + 1, remove);
}

int remove_nim(int **map, int *total, int max)
{
    int remove = nim_sum(map);
    int n_matches = 0;
    int i = 0;

    if (remove > max)
        remove = max;
    while ((*map)[i] != -1) {
        n_matches = (*map)[i];
        if (remove <= n_matches) {
            match_removed(remove, total, map, i);
            return (0);
        }
        i++;
    }
}

int remove_match(int **map, int max, input_t *input, int *total)
{
    if (check_win(map, max) == true) {
        win_move(map, max, total);
    } else {
        remove_nim(map, total, max);
    }
}