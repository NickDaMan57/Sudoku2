#include "sudoku.h"

/*
 * quadFunc(int) rceives one parameter for the
 * board-position and returns the quadrant it
 * belongs to.
 * Returns -1 on error.
*/
int quadFunc(int v){
    if(col(v) < 3) {
        if(v < 21) {
            return 0; }
        else if(v < 48) {
            return 3; }
        else if (v < 75) {
            return 6; }
    }
    else if(col(v) < 6) {
        if(v < 24) {
            return 1; }
        else if(v < 51) {
            return 4; }
        else if (v < 78) {
            return 7; }
    }
    else if(col(v) < 9) {
        if(v < 27) {
            return 2; }
        else if(v < 54) {
            return 5; }
        else if (v < 81) {
            return 8; }
    }

    return -1;
}
