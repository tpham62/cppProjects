#include <iostream>
#include <string>
#include "Ant.hpp"

/***********************************************************
** Sets the starting point of the ant
***********************************************************/
void Ant::setStart(int row, int col, int startR, int startC, char **nBoard)
{
    int aCount,
        bCount;

    nBoard[startR][startC] = '*';

    /**************************************************
    ** Prints board with starting point ant
    **************************************************/
    for (aCount = 0; aCount < row; ++aCount){ 
        for (bCount = 0; bCount < col; ++bCount){
            std::cout << nBoard[aCount][bCount];
        }
    std::cout << std::endl;
    }
}

/**************************************************************
** Makes the board with given row and col through a pointer
** to the dynamically created array
**************************************************************/
void Ant::makeBoard(int row, int col, char **board)
{
    int aCount,
        bCount,
        cCount,
        dCount,
        xCount,
        yCount,
        row1 = row - 1,
        col1 = col - 1;

    for (aCount = 1; aCount < row1; ++aCount){
        for (bCount = 1; bCount < col1; ++bCount){
            board[aCount][bCount] = ' ';
        }
    }

    for (cCount = 0; cCount < col; cCount++){
        board[cCount][0] = '|';
    }

    for (xCount = 0; xCount < col; xCount++){
        board[xCount][col1] = '|';
    }

    for (dCount = 0; dCount < row; dCount++){
        board[0][dCount] = '-';
    }

    for(yCount = 0; yCount < row; yCount++){
        board[row1][yCount] = '-';
    }
}

/********************************************************
** Function that checks each space according to color
** then makes the decision to turn a certain direction
** based on the color and moves forward while changing
** previous space into the oppositie color it originally
** was.
********************************************************/
void Ant::makeMove(int a, int b, int x, int y, std::string direction, char color, int moves,  char **board)
{
    int count,
        row = x,
        column = y,
        aCount,
        bCount,
        cCount,
        dCount;

    
    for (count = 0; count < moves; count++){
        if (direction == "up" && color == ' '){
            if (board[x][y+1] == ' '){
                color = ' ';
                board[x][y] = '#';
                board[x][y+1] = '*';
                direction = "right";
                y = y + 1;}
       else if (board[x][y+1] == '#'){
                color = '#';
                board[x][y] = '#';
                board[x][y+1] = '*';
                direction = "right";
                y = y + 1;}
          else{
                direction = "right";}
         }
                

   else if (direction == "up" && color == '#'){
            if (board[x][y-1] == ' '){
                color = ' ';
                board[x][y] = ' ';
                board[x][y-1] = '*';
                direction = "left";
                y = y - 1;}
       else if (board[x][y-1] == '#'){
                color = '#';
                board[x][y] = ' ';
                board[x][y-1] = '*';
                direction = "left";
                y = y-1;}
           else{
                direction = "left";}
         }

    else if (direction == "right" && color == ' '){
             if (board[x+1][y] == ' '){
                 color = ' ';
                 board[x][y] = '#';
                 board[x+1][y] = '*';
                 direction = "down";
                 x = x + 1;}
        else if (board[x+1][y] == '#'){
                 color = '#';
                 board[x][y] = '#';
                 board[x+1][y] = '*';
                 direction = "down";
                 x = x+1;}
           else{
                 direction = "down";}
         }

    else if (direction == "right" && color == '#'){
             if (board[x-1][y] == ' '){
                 color = ' ';
                 board[x][y] = ' ';
                 board[x-1][y] = '*';
                 direction = "up";
                 x = x - 1;}
        else if (board[x-1][y] == '#'){
                 color = '#';
                 board[x][y] = ' ';
                 board[x-1][y] = '*';
                 direction = "up";
                 x = x - 1;}
           else{
                 direction = "up";}
         }

    else if (direction == "down" && color == ' '){
             if (board[x][y-1] == ' '){
                 color = ' ';
                 board[x][y] = '#';
                 board[x][y-1] = '*';
                 direction = "left";
                 y = y - 1;}
        else if (board[x][y-1] == '#'){
                 color = '#';
                 board[x][y] = '#';
                 board[x][y-1] == '*';
                 direction = "left";
                 y = y - 1;}
           else{
                 direction = "left";}
         }

    else if (direction == "down" && color == '#'){
             if (board[x][y+1] == ' '){
                 color = ' ';
                 board[x][y] = ' ';
                 board[x][y+1] = '*';
                 direction = "right";
                 y = y + 1;}
        else if (board[x][y+1] == '#'){
                 color = '#';
                 board[x][y] = ' ';
                 board[x][y+1] = '*';
                 direction = "right";
                 y = y + 1;}
           else{
                 direction = "right";}
         }

    else if (direction == "left" && color == ' '){
             if (board[x-1][y] == ' '){
                 color = ' ';
                 board[x][y] = '#';
                 board[x-1][y] = '*';
                 direction = "up";
                 x = x - 1;}
        else if (board[x-1][y] == '#'){
                 color = '#';
                 board[x][y] = '#';
                 board[x-1][y] = '*';
                 direction = "up";
                 x = x - 1;}
           else{ 
                 direction = "up";}
         }

    else if (direction == "left" && color == '#'){
             if (board[x+1][y] == ' '){
                 color = ' ';
                 board[x][y] = ' ';
                 board[x+1][y] = '*';
                 direction = "down";
                 x = x +1;}
        else if (board[x+1][y] == '#'){
                 color = '#';
                 board[x][y] = ' ';
                 board[x+1][y] = '*';
                 direction = "down";
                 x = x + 1;}
           else{ 
                 direction = "down";}
         }

    /***************************************************
    ** For loop that prints out board each time a move
    ** has been played.
    ***************************************************/
         for (aCount = 0; aCount < a; ++aCount){
             for (bCount = 0; bCount < b; ++bCount){
                 std::cout << board[aCount][bCount];
             }
             std::cout << std::endl;
         }
    }
}


