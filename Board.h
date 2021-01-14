//
// Created by Sawyer on 1/11/2021.
//

#ifndef CHECKERS_GAME_BOARD_H
#define CHECKERS_GAME_BOARD_H

#include "Cell.h"

class Board {
    Cell board[8][8]; // Array of cells, represents the board.
    void printBoard();
    bool validateMove(int startConvert[2], int endConvert[2], int player); //return bool value on validity on move, leaving parameters blank until they're finalised
    void resetBoard();
};


#endif //CHECKERS_GAME_BOARD_H
