#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include "generator.h"

void printBoard(struct gameBoard board); 

int main(void);

void reveal(struct gameBoard * board_ptr, int x, int y);

void dig(struct gameBoard * board_ptr, int x, int y);

void oneMove(struct gameBoard * board_ptr);

int win(struct gameBoard * board_ptr);

#endif