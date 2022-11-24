#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>

#include "generator.h"

/* Generates the board and makes changes to the board */
/* - Need to create generic board generator
   - need some sort of "visible board" and actual board. */

struct gameBoard createBoard(uint8_t size,uint8_t mines){

        struct gameBoard board;
        board.boardSize = size;
        board.numOfMines = mines;

        board.board = (int8_t *)calloc(size*size, sizeof(int8_t));

        
        int randCoord;
        struct timeval ct;
        gettimeofday(&ct, NULL);
        int seed = ct.tv_usec;
        for ( int x = 0; x < board.numOfMines; x++ ){
            randCoord = randomCoord(board.boardSize, &seed);

            while (board.board[randCoord] == -1){
                randCoord = randomCoord(board.boardSize, &seed);
            }

            board.board[randCoord] = -1;
        }

        return board;

};


int randomCoord(uint8_t boardSize, int *seed){
    uint8_t randCoord;
    *seed = hash(*seed);
    randCoord = (*seed) % ((boardSize*boardSize));
    return randCoord;
}

int hash(int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}