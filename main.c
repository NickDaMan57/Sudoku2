#include "sudoku.h"

/*  Global Variable Declaration */
int* eraset;        //Pointer to array of elements to be hidden
int editFlag = -1;   //Tracks if game is in edit mode or not

/*
 * main() will:
 * 1) set a loop to clear all elements
 *      of the board
 * 2) Request user for number of elements
 *      to hide from view (difficulty)
 * 3) Call the fillBoard() function
 * 4) Call initial printBoard() function
 * 5) Pass control to select which captures
 *      and responds to user input
 */
int main(void){
    srand(time(NULL));
    int e;

    for(int i = 0; i < 81; i++){
        structInit(i);
    }

    //printf("%d", getch());

    printf("How many elements to hide[1-81]?");
    scanf("%d", &e);

    while(e < 1 || e > 80){
        printf("\nInvalid. Enter a number from 1 (noob) to 80 (bullshit): ");
        scanf("%d", &e);
    }

    system("cls");

    //Generate list of items to be deleted.
    eraset = eraser(e);

    //Generate a new board.
    fillBoard();

    //Print the board
    printBoard(0);

    //Pass control to selector.
    select(0);

    return 1;
}

