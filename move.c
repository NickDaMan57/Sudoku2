#include "sudoku.h"

/*
 * movet(int) receives one parameter for
 * the current board position and returns
 * the position after reading user input.
 *
 * This function is used inside a loop for
 * continuous input-read.
 *
 * Accepted user inputs:
 * - Left arrow
 * - Up arrow
 * - Right arrow
 * - Down arrow

 * NOTE1:
 * getch() captures arrow key strokes in a strange way. When getch() caputres
 * a non-arrow key press, it returns an integer value correspondent to the key
 * pressed. With arrows, however, it returns two consecutive getch() calls.
 * The first call is returned with value 224 and the second call is returned
 * with values as described by the macros in sudoku.h. Therefore when comment
 * mentions "catch user input" it merely calls the function and automatically
 * gets a return correspondent to the key press that returned 224 on the call
 * from the selector.
 */
int movet(int i)
{
    //Catch user input and move selector accordingly. Read NOTE1 on header comment.
    switch (getch()) {
        case LEFT:
            if(col(i) == 0){
                i += 8;
                return i;
            }
            i--;
            break;
        case UP:
            if(row(i) == 0){
                i += 72;
                return i;
            }
            i -= 9;
            break;
        case RIGHT:
            if(col(i) == 8){
                i -= 8;
                return i;
            }
            i++;
            break;
        case DOWN:
            if(row(i) == 8){
                i -= 72;
                return i;
            }
            i += 9;
            break;
        default:
            break;
    }

    return i;
}
