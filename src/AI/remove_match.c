/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-matchstick-pol.aragones
** File description:
** remove_match
*/

#include "matchstick.h"

int remove_match(int **map, int max, input_t *input, int *total)
{
    int remove = max - input->matches;
    int n_matches = 0;
    int i = 0;

    my_putstr("\nAI's turn...\n");
    if (remove <= 0)
        remove = 1;
    while ((*map)[i] != -1) {
        n_matches = (*map)[i];
        if (remove <= n_matches) {
            (*map)[i] -= remove;
            *total -= remove;
            print_ai(i + 1, remove);
            return (0);
        }
        i++;
    }
    remove_match(map, max - 1, input, total);
}