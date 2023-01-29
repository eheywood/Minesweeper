#include "main.h"

/* Print board function */

void printBoard(struct gameBoard board){

    for (int i = 0 ; i < board.boardSize ; i ++){
        if (i == 0){
            printf("  │ %d",i);
        } else {
            printf("  %d", i);
        }
    }
    printf("\n");

    for (int i = 0 ; i < (board.boardSize*3)+2 ; i ++){
        
        if(i == 2){
            printf("┼");
        } else {
            printf("─");
        }
    }
    printf("\n");

    for ( int y = 0; y < board.boardSize; y++){
        for( int x = 0 ; x < board.boardSize; x++){
            if (x == 0){
                printf("%d │ ", y);
            }

            if (board.board[(y*(board.boardSize))+x] == -1){
                printf("x  ");
            } else {
                printf("%d  ", board.board[(y*(board.boardSize))+x]);
            }

            if (((x+1) % board.boardSize) == 0){
                printf("\n");
            }
        }
    }
};


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
    printBoard(board);


    /* Player enter co-ordinates of sqaure to check for mine */

    return 0;
}


