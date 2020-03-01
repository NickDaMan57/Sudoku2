#include "sudoku.h"

/*
 * structInit(int) receives one parameter for the
 * current board position and sets the struct for
 * that position to zeros. This is done to avoid
 * starting the board with values and messing up
 * the entire validity-check process.
 *
 * This function is called once per game.
 *
 */
void structInit(int i){
    board[i].val = 0;
    board[i].triedO = 0;
    board[i].input = 0;
}
