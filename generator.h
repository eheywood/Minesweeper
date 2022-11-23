#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdint.h>



struct gameBoard {
    uint8_t boardSize;
    uint8_t numOfMines;

    int *board;

    
};

int test(int);

struct gameBoard createBoard(uint8_t,uint8_t);

#endif