#include "sudoku.h"

/*
 * edit() function receives one integer for the
 * current position on board.
 *  This function will raise a global flag editFlag
 * to let the system know edit mode is activated
 * and reprint the board (which will result in the
 * current position 'i' being shown as a dot [.]).
 *  The function then enter a loops that will wait
 * for user input and only exit if input is ENTER.
 *  A conditional statement catches arrow keys, which
 * are parsed through getch as 2 key presses.
 * Another conditional statement catches valid values
 * 1-9 as input and changes the input value of position
 * accordingly.
 * The function then removes the flag to default -1.
 */
void edit(int i)
{
    int tmp = 0;            //Throwaway variable

    board[i].input = tmp;   //Erase whatever input value is being displayed on board
    editFlag = i; //Set flag value to current board's position
    system("cls");
    printBoard(i);

    //Loop while user input != ENTER
    while((tmp = getch()) != 13) {
        //Conditional if arrow key was pressed, ignore.
        if (tmp == 224){
            getch();
        }

        //Conditional else if key pressed was a number, set input to value.
        else if((tmp >= 48) && (tmp <= 57)){
            tmp = tmp-48;
            board[i].input = tmp;
        }

        system("cls");
        printBoard(i);
    }

    editFlag = -1;  //Lower flag
}
