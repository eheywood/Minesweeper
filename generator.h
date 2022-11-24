#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdint.h>



struct gameBoard {
    uint8_t boardSize;
    uint8_t numOfMines;

    int8_t *board;

    
};

struct gameBoard createBoard(uint8_t,uint8_t);

int randomCoord(uint8_t, int *seed);

int hash(int x);

#endif