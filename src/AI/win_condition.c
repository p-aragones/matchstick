/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-matchstick-pol.aragones
** File description:
** win_condition
*/

#include "matchstick.h"

bool check_win(int **map, int max)
{
    int i = 0;
    int first_line = -1;
    int second_line = -1;
    int n = 0;

    while ((*map)[i] != -1) {
        if ((*map)[i] > 1)
            n++;
        i++;
    }
    if (n == 1)
        return (true);
    return (false);
}

int get_remove(int remove, int max, int line)
{
    if (remove <= max)
        return (remove);
    if (line - max - 1 > 0)
        return (max - 1);
    return (1);
}

int n_lines(int **map)
{
    int i = 0;
    int n = 0;

    while ((*map)[i] != -1) {
        if ((*map)[i] > 0)
            n++;
        i++;
    }
    return (n);
}

int win_move(int **map, int max, int *total)
{
    int remove = 0;
    int lines = n_lines(map);
    int i = 0;

    if (lines % 2 == 0)
        even_move(map, total, max);
    else
        odd_move(map, total, max);
    return (0);
}