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

    //Generate the mines
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

    //Fill in the rest of the numbers on the board

    for ( int y = 0; y < board.boardSize; y++){
        for( int x = 0 ; x < board.boardSize; x++){ 
            if (board.board[(y*(board.boardSize))+x] != -1){
                int8_t neighMines = getNeighbourMines (&board, x, y);
                board.board[(y*(board.boardSize))+x] = neighMines;
            }
        }
    }    
    return board;
};


int8_t getNeighbourMines (struct gameBoard * board_ptr, uint8_t x, uint8_t y){
    int8_t mines = 0;

    for (int x_offset = -1; x_offset < 2; x_offset++) {
        for (int y_offset = -1; y_offset < 2; y_offset++) {
            if ((x + x_offset < 0) || (x + x_offset > board_ptr->boardSize) || (y + y_offset < 0) || (y + y_offset > board_ptr->boardSize)) {
                continue;
            }

            if (board_ptr->board[(y + y_offset) * board_ptr->boardSize+(x+x_offset)] == -1) {
                mines += 1;
            }
        }
    }
    
    return mines;
}


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