/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** create_map
*/

#include "utils.h"

int *create_map(int n)
{
    int i = 1;
    int *map = malloc(sizeof(int) * (n + 1));

    if (map == NULL)
        return (NULL);
    while (i <= n) {
        map[i - 1] = 2 * i - 1;
        i++;
    }
    map[i - 1] = -1;
    return (map);
}