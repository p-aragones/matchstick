/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-matchstick-pol.aragones
** File description:
** even_move
*/

#include "matchstick.h"

void remove_even(int **map, int *total, int max, int i)
{
    if ((*map)[i] <= max) {
        match_removed((*map)[i], total, map, i);
    } else {
        match_removed(1, total, map, i);
    }
}

int even_move(int **map, int *total, int max)
{
    int i = 0;

    while ((*map)[i] != -1) {
        if ((*map)[i] > 1) {
            remove_even(map, total, max, i);
            return (0);
        }
        i++;
    }
    i = 0;
    while ((*map)[i] != -1) {
        if ((*map)[i] == 1) {
            remove_even(map, total, max, i);
            return (0);
        }
        i++;
    }
    return (0);
}