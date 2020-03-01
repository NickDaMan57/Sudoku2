#include "sudoku.h"

/*
 * incVal receives one parameter, increments
 * that value by one, and loops it to 1 if
 * it is larger than 9. This is intended for
 * avoiding overflow row, col, or quadrant
 * positions.
 */
int incVal(int val)
{
    val++;
    if(val == 10) { val = 1;}
    return(val);
}
