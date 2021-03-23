/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-matchstick-pol.aragones
** File description:
** int_to_bin
*/

int int_to_bin(int n)
{
    long r = 0;
    long binary = 0;
    int temp = 1;

    while (n != 0) {
        r = n % 2;
        n = n / 2;
        binary = binary + r * temp;
        temp = temp * 10;
    }
    return (binary);
}