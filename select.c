#include "sudoku.h"

/*
 * select(int) receives current board
 * position and locks user in a loop
 * until specific keys are pressed.
 *
 * This function will loop until on of
 * the following keys are pressed:
 * - ESC: kills loop, likely exits game
 * - ENTER: enters/exits EDIT mode,
 *      only if position is on removed list.
 */
void select(int i)
{
    int s;

    //Loop while input != ESC
    while((s = getch()) != 27) {
        //Conditional if input == ARROWS
        if(s == 224){
            //Pass control to mover.
            i = movet(i);
        }
        //Conditional else if input == ENTER and board element is empty
        else if((s == 13) && isRemoved(i)){
            //Pass control to editor.
            edit(i);
        }

        system("cls");
        printBoard(i);

        //Conditional if any empty board elements remains unfilled
        if (gameOver() == 1){
            //Reply aggressively and end program.
            printf("\n\nFUCK YOU, YOU WIN.\n\n");
            break;
        }
        //Conditional else if all empty board elements are filled
        else if (gameOver() == 0){
            //Reply aggressively and end program.
            printf("\n\nARE YOU FUCKING STUPID? YOU FUCKED UP!\n\n");
        }
    }
}
