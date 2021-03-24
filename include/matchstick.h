/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include "utils.h"
#include "input.h"

void print_map(int *, int);
int *create_map(int);

int get_line(int, input_t *, int *);
int get_matches(int, input_t *, int *);
int handle_input(input_t *, int, int *, int);
void init_input(input_t *, int);

int ai_turn(int **, int, input_t *, int *);
int remove_match(int **, int, input_t *, int *);
void match_removed(int, int *, int **, int);
void ai_lost(int **);
int int_to_bin(int);
int *bin_array(int **, int);
int nim_sum(int **);

int win_move(int **, int, int *);
bool check_win(int **, int);

void print_ai(int, int);
void print_player(int, int, int **, int *);

int matchstick(int, int);

#endif /* !MATCHSTICK_H_ */
