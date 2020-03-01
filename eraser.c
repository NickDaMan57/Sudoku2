#include "sudoku.h"

/*
 * eraser(int) receives a parameter defining how many
 * elements will be hidden from the board. It returns
 * a pointer to a manually allocated array of integers.
 *
 * remove_ids[0] contains the size of the array
 * remove_ids[>0] contain unique elements to be hidden
 */
int* eraser(int array_size)
{
    array_size++;
    int* remove_ids = malloc(sizeof(int*) * array_size);
    int t;
    int i;

    for(i = 0; i < array_size; i++)    {
        t = rand() % 80;

        remove_ids[i] = t;

        if(i == 0){
            remove_ids[i] = array_size;
        }
        else {
            for(int c = 1; c < i; c++) {
                if(remove_ids[c] == t) {
                    i--;
                    break;
                }
            }
        }

        //printf("r_d[i]=%d, i=%d \n", remove_ids[i], i);
    }

    return(remove_ids);
}
