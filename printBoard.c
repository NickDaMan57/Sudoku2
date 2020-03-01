#include "sudoku.h"

/*
 * printBoard() receives one parameter defining which
 * position selected. It will print the formatted board
 * unto the screen, hiding the elements in array erasert.
 *
 * param s = selected id
 * dnp = do_not_print flag. Default = 0. When raised, do
 *      not print value
 *
 */
void printBoard(int s) {
    int dnp = 0;    //do_not_print flag

    /*  Header  */
    printf("########## SUDOKU2 ##########\n");

    //Formatting loop
    for(int i =0; i < 81; i++) {
        if(isRemoved(i)) {dnp = 1;}

        /*  Left Side   */
        if(i == s) {    //Selected
            printf("[");
        }
        else if(dnp) {  //Variable values
            printf(" ");
        }
        else {  //Fixed values
            printf("-");
        }
        /*  */

        /*  Center  */
        if(dnp) {
            if((editFlag == i) && board[i].input == 0)  //Edit Mode and no current value
            {
                printf(".");
            }
            else if((editFlag == i) && board[i].input != 0) //Edit Mode and current value set
            {
                printf("%d", board[i].input);
            }
            else if((editFlag != i) && (board[i].input != 0))   //Not edit mode and current value set
            {
                printf("%d", board[i].input);
            }
            else if(board[i].input == 0)    //Not edit mode and no current value
            {
                printf(" ");
            }
        }
        else {  //Fixed values
            printf("%d", board[i].val);
        }
        /*  */


        /*  Right Side  */
        if(i == s) {    //Selected
            printf("]");
        }
        else if(dnp) {  //Variable values
            printf(" ");
        }
        else {  //Fixed values
            printf("-");
        }
        /*  */


        /* Dividers */
        //Conditional if current row != new row (end of line)
        if(row(i) != row(i+1)){
            printf("\n");

            //Conditional if current row == 2 || 5 (end of quadrant)
            if((row(i) == 2 || row(i) == 5)){
                printf("---------+---------+---------\n");
            }
        }

        //Conditional if current column == 2 || 5 (end of quadrant)
        if((col(i) == 2) || (col(i) == 5)){
            printf("|");
            //printf(" ");
        }

        dnp = 0;    //Lower flag
    }

    /*  Footer  */
    printf("#############################\n");
}
