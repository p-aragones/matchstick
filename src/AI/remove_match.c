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

int remove_match(int **map, int max, input_t *input, int *total)
{
    int remove = max - input->matches;
    int n_matches = 0;
    int i = 0;

    if (remove <= 0)
        remove = 1;
    while ((*map)[i] != -1) {
        n_matches = (*map)[i];
        if (remove <= n_matches) {
            match_removed(remove, total, map, i);
            return (0);
        }
        i++;
    }
    remove_match(map, max - 1, input, total);
}