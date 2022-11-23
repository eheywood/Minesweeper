#include <stdio.h>

#include "main.h"
#include "generator.h"


int main() {

    uint8_t boardSize;
    uint8_t numOfMines;
    struct gameBoard board;

    printf("Please enter the size of the board you want to play on: ");
    scanf("%d", &boardSize);
    printf("Please enter the number of mines you want on the board: ");
    scanf("%d", &numOfMines);

    /* Create the board */
    board = createBoard(boardSize, numOfMines);
    

    /* Print the board */

    /* Player enter co-ordinates of sqaure to check for mine */

    
    return 0;
}
