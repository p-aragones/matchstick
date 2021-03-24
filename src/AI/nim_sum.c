/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-matchstick-pol.aragones
** File description:
** nim_sum
*/

int nim_sum(int **map)
{
    int i = 0;
    int result = 0;

    while ((*map)[i] != -1) {
        result = result ^ (*map)[i];
        i++;
    }
    return (result);
}