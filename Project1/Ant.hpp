#ifndef ANT_HPP
#define ANT_HPP
#include <string>

/*************************************************
** Class ant that sets the start of the ant,
** makes the board, and makes moves while printing
** the board after each move.
*************************************************/
class Ant
{
    public:
        void setStart(int, int, int, int, char **nBoard);
        void makeBoard(int, int, char  **board);
        void makeMove(int, int, int, int, std::string, char, int, char **board);
};

#endif
