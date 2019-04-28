#include <iostream>
#include "Ant.hpp"
#include "menu.hpp"
#include <string>

std::string menu()
{
    int row,
        col,
        steps,
        startRow,
        startCol,
        zCount,
        count,
         col1,
         row1,
         input,
         last;

    std::string dir = "up";
           char clr = ' ';

    Ant ant1;

    /******************************************************
    ** Do while loop that restarts the loop if user inputs
    ** 1 or quits if 2
    ******************************************************/
    do
    {
        /*******************************************************************
        ** Do while loop that asks for number of rows and columns
        ** while creating a buffer for the boarders
        *******************************************************************/
        do
        {
            std::cout << "Please enter the number of rows(using whole numbers only) for the board." << std::endl;
            std::cin >> row;

            if (row <= 0)
                std::cout << "Please enter a positive number." << std::endl;

        }while (row <= 0 || row > 100000);

        row = row + 2;
        row1 = row - 2;

        do
        {
                std::cout << "Please enter the number of columns for the board." << std::endl;
                std::cin >> col;
               
                if (col <= 0)
                    std::cout << "Please enter a positive number." << std::endl;

        }while (col < 0 || col > 100000);

        col = col + 2;
        col1 = row - 2;

        /*******************************************************
        ** Do while loopos that asks for number of steps
        ** starting row and starting col
        *******************************************************/
        do
        {
            std::cout << "Enter the amount of steps during the simulation." << std::endl;
            std::cin >> steps;

            if (steps < 0)
                std::cout << "Please enter a positive number." << std:: endl;

        }while (steps < 0);
        
        do
        {
            std::cout << "Enter the starting row of the ant." << std::endl;
            std::cin >> startRow;
            startRow = startRow + 1;

            if (startRow < 0 || startRow > row1)
                std::cout << "Enter a number that is not greater than the amount of rows and is a positive number." << std::endl;
        }while (startRow < 0 || startRow > row1);

        do
        {
            std::cout << "Enter the starting column of the ant." << std::endl;
            std::cin >> startCol;
            startCol = startCol + 1;

            if (startCol < 0 || startCol > col1)
                std::cout << "Enter a number that is not greater than the amount of columns and is a positive number." << std::endl;
        }while (startCol < 0 || startCol > col1);
 
        /****************************************************************
        ** Initializes 2d array that will contain chars
        ****************************************************************/        
        char** mArray = new char*[row];
        for (count = 0; count < row; ++count)
            mArray[count] = new char[col];

        ant1.makeBoard(row, col, mArray);
        ant1.setStart(row, col, startRow, startCol, mArray);
        ant1.makeMove(row, col, startRow, startCol, dir, clr, steps, mArray);

        /******************************************************************
        ** Deletes the array
        ******************************************************************/
        for(last = 0; last < row; ++last){
            delete [] mArray[last];
        }
        delete [] mArray;
    
        /*****************************************************************
        ** Do while loop that asks for input to continue or quit
        *****************************************************************/
        do
        {
            std::cout << "The simulation has ended. Press 1 to restart the simulation or 2 to exit." << std::endl;
            std::cin >> input;

            if (input != 1 && input !=2)
                std::cout << "Please enter a valid number." << std::endl;

        }while (input != 1 && input != 2);

        if (input == 2)
            return "Thanks for playing";

    }while (input == 1);
    
}
