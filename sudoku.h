#ifndef SUDOKU_H
#define SUDOKU_H

/*  Libraries */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

/*  Macros  */
#define row(x)  ((x)/9)             //Calculate row value of position
#define col(x)  ((x)-(9*row(x)))    //Calculate column value of position
#define BOARD_SIZE 81

/*  getch() values */
#define EXIT 27     //ESC key
#define LEFT 75     //Left arrow key
#define UP 72       //Up arrow key
#define RIGHT 77    //Right arrow key
#define DOWN 80     //Down arrow key

/*  Function prototypes */
//Check function files for descriptions
int quadFunc(int);
void fillBoard();
void printBoard(int);
int isValid(int);
void structInit(int);
int incVal(int);
int* eraser(int);
void select(int);
int movet(int);
void edit(int);
int isRemoved(int);
int gameOver();

/*  Struct declaration  */
typedef struct {
        int val;    //Current value of slot
        int triedO; //Original value attempt
        int input;
}spaceb;

/*  Global variables    */
extern int* eraset;         //Global pointer to manually-allocated array of erasable items
spaceb board[BOARD_SIZE];   //Global array for board
extern int editFlag;   //Tracks if game is in edit mode or not

#endif  //SUDOKU_H
