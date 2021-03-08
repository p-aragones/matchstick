/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** remake of tcsh
*/

#include "matchstick.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    else if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0)
        return (84);
    return (matchstick(my_getnbr(av[1]), my_getnbr(av[2])));
}