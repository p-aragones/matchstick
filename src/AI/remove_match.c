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

int remove_from_line(int *remove, int **map)
{
    int *nim = remove;
    int sum = 0;
    int line = 0;
    int i = 0;

    while ((*map)[i] != -1) {
        sum = *nim ^ (*map)[i];
        if (sum < (*map)[i]) {
            *remove = (*map)[i] - sum;
            return (i);
        }
        i++;
    }
    return (-1);
}

int remove_random(int *remove, int **map)
{
    int i = 0;

    *remove = 1;
    while ((*map)[i] != -1) {
        if ((*map)[i] > 1)
            return (i);
        i++;
    }
    i = 0;
    while ((*map)[i] != -1) {
        if ((*map)[i] == 1)
            return (i);
        i++;
    }
    return (1);
}

int remove_nim(int **map, int *total, int max)
{
    int remove = nim_sum(map);
    int line = remove_from_line(&remove, map);
    int n_matches = 0;
    int i = 0;

    if (remove == -1)
        line = remove_random(&remove, map);
    if (remove > max || remove <= 0)
        remove = 1;
    match_removed(remove, total, map, line);
}

int remove_match(int **map, int max, input_t *input, int *total)
{
    if (check_win(map, max) == true) {
        win_move(map, max, total);
    } else {
        remove_nim(map, total, max);
    }
}