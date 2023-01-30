#include "main.h"

/* Print board function */

void printBoard(struct gameBoard board){

    /* ■ -> for undug squares (0 on mask) */

    /* ⚑ -> for flagged squares (2 on mask)*/

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


    /* While not won, call oneMove */

    while(win(&board) == 0){
        oneMove(&board);
    }


    return 0;
}

void reveal(struct gameBoard * board_ptr, int x, int y){
    /* When a player chooses to dig and doesnt hit a mine. 
    Calculates what to reveal to the player. */


}

void dig(struct gameBoard * board_ptr, int x, int y){
    if (board_ptr->board[(y*(board_ptr->boardSize))+x] == -1){
        printf("Oh no! You hit a mine! Game over.");
    } else {
        reveal (board_ptr,x,y);
    }
}

void oneMove(struct gameBoard * board_ptr){

    int8_t x,y;
    char opt = ' ';

    printf("Please enter the x-coordinate:");
    scanf("%d", &x);

    printf("Please enter the x-coordinate:");
    scanf("%d", &y);

    printf("Please enter d for dig, f for flag and r to re-enter the co-ordinate:");
    scanf(" %c", &opt);

    if(opt == 'd'){
        dig(board_ptr,x,y);
    } else if (opt == 'f'){
        /*flag that spot (change mask to 2??)*/
    } else if (opt == 'r'){
        oneMove(board_ptr);
    } else {
        printf("Please only enter either d,f or s. Try again. \n");
        oneMove(board_ptr);
    }
}


int win(struct gameBoard * board_ptr){

    /* Win if no 0's left in the mask */

    int win = 1;

    for ( int y = 0; y < board_ptr->boardSize; y++){
        for( int x = 0 ; x < board_ptr->boardSize; x++){
            if (board_ptr->mask[(y*(board_ptr->boardSize))+x] == 0){
                win = 0;
                break;
            }
        }
    }  

    return win;  
}

