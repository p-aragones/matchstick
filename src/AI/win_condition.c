/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-matchstick-pol.aragones
** File description:
** win_condition
*/

#include "matchstick.h"

void save_lines(int *first_line, int *second_line, int *n, int i)
{
    *n += 1;
    if (*first_line == -1) {
        *first_line = i;
    } else {
        *second_line = i;
    }
}

bool check_win(int **map, int max)
{
    int i = 0;
    int first_line = -1;
    int second_line = -1;
    int n = 0;

    while ((*map)[i] != -1) {
        if ((*map)[i] > 0)
            save_lines(&first_line, &second_line, &n, i);
        i++;
    }
    if (n == 2 && ((*map)[first_line] == 1 || (*map)[second_line] == 1))
        return (true);
    return (false);
}

int win_move(int **map, int max, int *total)
{
    int remove = 0;
    int i = 0;

    while ((*map)[i] != -1) {
        remove = (*map)[i];
        if (remove > max)
            remove = max;
        if ((*map)[i] != 0 || (*map)[i] != 1) {
            match_removed(remove, total, map, i);
            return (0);
        }
        i++;
    }
    return (0);
}


