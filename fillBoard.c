#include "sudoku.h"

/*
 * fillBoard() is a function called only once per game. It simply loops
 * through the board array assigning random numbers for each value and
 * calling isValid() to check the validity of numbers. In cases where
 * it is invalid, it will increment board[].val by one and check
 * validity again until a valid value is found.
 * In cases where no value is found, it will take a step back to the
 * previous board location, increment the board[].val, and repeat
 * the loop until a value is found.

 * NOTE1:
 * The loop here is a little tricky to grasp, so I will explain in more
 * detail here.
 *
 * ** while(((board[i].triedO - board[i].val) == 1) || ((board[i].triedO - board[i].val) == -8)) **
 *
 * When a random number is assigned to the board element 'i', it has to pass the validity
 * test. If the validity test fails the program increments the value of the position through
 * incVal() and checks for validity again. At one point all values from 0-9 will have been attempted,
 * at which point the second loop kicks in.
 * The second loops checks if the (original value - current value == 1 || 8). If we started with value
 * 5, and subsequently tested 6, 7, 8, 9, 1, 2, 3, 4, at this point attempting 5 again will through us
 * in an infinite loop. So original value - current value = 1 (5-4=1). If the original value == 1 then
 * (1-9=-8).
 * When this condition is met the program reinitializes the position and steps back to the previous
 * board location for a new attempt. If the attempt that just failed (described above) was this new
 * position's last allowable attempt, then the program will stay within the step back loop and go back
 * again. It will repeat this until a valid position is found.
 */
void fillBoard() {
    for(int i = 0; i < BOARD_SIZE; i++) {
            board[i].val = 1 + (rand() % 9);
            board[i].triedO = board[i].val;

        //Loop while input value is invalid as per sudoku's 3 rules
        while(!isValid(i)) {
            //Loop while all values have already been attempted. Read NOTE1 on header comment.
            while(((board[i].triedO - board[i].val) == 1) || ((board[i].triedO - board[i].val) == -8)) {  //step back
                //Reinitialize board element
                structInit(i);
                //Move back to previous board element
                i--;
            }
            //Increment current value of board element
            board[i].val = incVal(board[i].val);
        }
    }
}
