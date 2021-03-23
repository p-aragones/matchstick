/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-matchstick-pol.aragones
** File description:
** bin_array
*/

#include "matchstick.h"

int *bin_array(int **map, int len)
{
    int *bin_array = malloc(sizeof(int) * (len + 1));
    int i = 0;

    while ((*map)[i] != -1) {
        bin_array[i] = int_to_bin((*map)[i]);
        i++;
    }
    bin_array[i] = -1;
    return (bin_array);
}