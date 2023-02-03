#include "main.h"

/* Print board function */

void printBoard(struct gameBoard * board_ptr){

    long int undug = '■';
    long int flag = '⚑';

    /* ■ -> for undug squares (0 on mask) */

    /* ⚑ -> for flagged squares (2 on mask)*/

    for (int i = 0 ; i < board_ptr->boardSize ; i ++){
        if (i == 0){
            printf("  │ %d",i);
        } else {
            printf("  %d", i);
        }
    }
    printf("\n");

    for (int i = 0 ; i < (board_ptr->boardSize*3)+2 ; i ++){
        
        if(i == 2){
            printf("┼");
        } else {
            printf("─");
        }
    }
    printf("\n");

    for ( int y = 0; y < board_ptr->boardSize; y++){
        for( int x = 0 ; x < board_ptr->boardSize; x++){
            if (x == 0){
                printf("%d │ ", y);
            }

            if(board_ptr->mask[(y*(board_ptr->boardSize))+x] == 1){
                if (board_ptr->board[(y*(board_ptr->boardSize))+x] == -1){
                    //printf("x  ");
                    continue;
                } else {
                    printf("%d  ", board_ptr->board[(y*(board_ptr->boardSize))+x]);
                }

            } else if (board_ptr->mask[(y*(board_ptr->boardSize))+x] == 2){
                printf("⚑  ");
                
            } else {
                printf("■  ");
            }
   

            if (((x+1) % board_ptr->boardSize) == 0){
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
    printBoard(&board);


    /* While not won, call oneMove */

    while(win(&board) == 0){
        oneMove(&board);
        printBoard(&board);
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

    int x, y;
    char opt;

    printf("Please enter the co-ordinate and option (d = dig, f = flag, r = re-enter) in the format: x,y option \n");
    scanf("%d,%d %c", &x, &y, &opt);

    if(opt == 'd'){
        dig(board_ptr,x,y);
    } else if (opt == 'f'){
        /*flag that spot (change mask to 2)*/
        *(board_ptr->mask + (((board_ptr->boardSize) * y) + x)) = 2;
    } else if (opt == 'r'){
        return;
    } else {
        printf("Please only enter either d,f or s. Try again. \n");
    }
}


int win(struct gameBoard * board_ptr){

    /* Win if no 0's left in the mask */

    for ( int y = 0; y < board_ptr->boardSize; y++){
        for( int x = 0 ; x < board_ptr->boardSize; x++){
            if (board_ptr->mask[(y*(board_ptr->boardSize))+x] == 0){
                return 0;
            }
        }
    }  

    return 1;  
}

