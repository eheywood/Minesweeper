#include <stdint.h>

#include "generator.h"

int test(int x){
    return x + 5;
}


/* Generates the board and makes changes to the board */
/* - Need to create generic board generator
   - need some sort of "visible board" and actual board. */

struct gameBoard createBoard(uint8_t size,uint8_t mines){

        struct gameBoard board;
        board.boardSize = size;
        board.numOfMines = mines;

        return board;

};