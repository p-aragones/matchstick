/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-matchstick-pol.aragones
** File description:
** ai_lost
*/

#include "utils.h"

void ai_lost(int **map)
{
    int i = 0;

    while ((*map)[i] != -1) {
        if ((*map)[i] == 1)
            (*map)[i] = 0;
        i++;
    }
}