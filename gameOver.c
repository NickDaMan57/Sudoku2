#include "sudoku.h"

/*
 * gameOver() function checks if all elements listed on
 * eraset[] array have received a user input. If any of
 * elements listed in eraser do not have an input value
 * the function will return 0. Otherwise it will return 1.
 */
int gameOver(){
    int t = 0;
    int fin = 1;

    for(int i = 1; i < eraset[0]; i++){
        t = eraset[i];
        if(board[t].input == 0) {
            return -1;
        }

        if(board[t].input != board[t].val){
            fin = 0;
        }
    }

    return fin;
}
