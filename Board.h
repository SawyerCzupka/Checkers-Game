//
// Created by Sawyer on 1/11/2021.
//

#ifndef CHECKERS_GAME_BOARD_H
#define CHECKERS_GAME_BOARD_H

#include "Cell.h"

class Board {

    void printBoard();
    bool validateMove(); //return bool value on validity on move, leaving parameters blank until they're finalised
    void resetBoard();

public:
    Cell * getBoard();
    Cell board[8][8]; // Array of cells, represents the board.
};


#endif //CHECKERS_GAME_BOARD_H
