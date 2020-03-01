#include "sudoku.h"

/*
 * isValid() receives one parameter as the current board
 * position, checks if the position's value is repeated
 * on the row, column, or quadrant, and returns TRUE or
 * FALSE for validity.
 *
 */
int isValid(int i) {
    for(int c = 0; c < 81; c++) {
        if(c == i) {
            c++;
        }
        if((row(c) == row(i)) && (board[c].val == board[i].val)) {
            return 0;
        }

        if((col(c) == col(i)) && (board[c].val == board[i].val)) {
            return 0;
        }

        if((quadFunc(c) == quadFunc(i)) && (board[c].val == board[i].val)) {
            return 0;
        }
    }

    return 1;
}
