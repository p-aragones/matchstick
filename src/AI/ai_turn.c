/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-matchstick-pol.aragones
** File description:
** ai_turn
*/

#include "matchstick.h"

int ai_turn(int **map, int max, input_t *input, int *total)
{
    if (*total == 0) {
        my_putstr("You lost, too bad...\n");
        return (2);
    } else {
        remove_match(map, max, input, total);
        if (*total == 0) {
            ai_lost(map);
            return (1);
        }
        return (0);
    }
}