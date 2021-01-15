
//
// Created by Sawyer on 1/11/2021.
//

#ifndef CHECKERS_GAME_BOARD_H
#define CHECKERS_GAME_BOARD_H

#include "Cell.h"

class Board {
public:
    Cell board[8][8]; // Array of cells, represents the board.

    void printBoard();
    bool validateMove(int startConvert[2], int endConvert[2], char currentMove); //return bool value on validity on move, leaving parameters blank until they're finalised
    void resetBoard();
    int Board::checkWinner(int pieceCount[2]);

    Board() {} //Dummy constructor
};


#endif //CHECKERS_GAME_BOARD_H