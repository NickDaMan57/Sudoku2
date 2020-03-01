#include  "sudoku.h"

/*
 * isRemoved receives an integer as the current position
 * on the board and checks if it belongs to the list
 * of removed elements.
 *
 * Returns:
 * 1 (TRUE) if position is in the removed list
 * 0 (FALSE) if position is not in removed list
 */
int isRemoved(int i)
{
    for (int j = 1; j < eraset[0]; j++){
        if (i == eraset[j]) {
            return 1;
        }
    }

    return 0;
}
