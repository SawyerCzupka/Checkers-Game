//
// Created by Sawyer on 1/11/2021.
//

#include "Board.h"
#include "Cell.h"

#include <iostream>

void Board::printBoard() {
    for (int i = 0; i < 8; i++) {
        std::cout << "-----------------------" << std::endl;
        for (int j = 0; j < 8; j++) {
            Cell current = this->board[i][j];

            if (current.getIsOccupied()) {
                switch (current.getPieceColor()) {
                    case 'r':
                        std::cout << "r";
                        break;
                    case 'b':
                        std::cout << "b";
                        break;
                    case 'n':
                        std::cout << "_";
                    default:
                        std::cout << "Error" << std::endl;
                        break;
                }
            }

            std::cout << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
}


void Board::resetBoard() {
    this->board[0][0] = Cell('n');
    this->board[0][1] = Cell('b');
    this->board[0][2] = Cell('n');
    this->board[0][3] = Cell('b');
    this->board[0][4] = Cell('n');
    this->board[0][5] = Cell('b');
    this->board[0][6] = Cell('n');
    this->board[0][7] = Cell('b');

    this->board[1][0] = Cell('b');
    this->board[1][1] = Cell('n');
    this->board[1][2] = Cell('b');
    this->board[1][3] = Cell('n');
    this->board[1][4] = Cell('b');
    this->board[1][5] = Cell('n');
    this->board[1][6] = Cell('b');
    this->board[1][7] = Cell('n');

    this->board[2][0] = Cell('n');
    this->board[2][1] = Cell('b');
    this->board[2][2] = Cell('n');
    this->board[2][3] = Cell('b');
    this->board[2][4] = Cell('n');
    this->board[2][5] = Cell('b');
    this->board[2][6] = Cell('n');
    this->board[2][7] = Cell('b');

    this->board[3][0] = Cell('n');
    this->board[3][1] = Cell('n');
    this->board[3][2] = Cell('n');
    this->board[3][3] = Cell('n');
    this->board[3][4] = Cell('n');
    this->board[3][5] = Cell('n');
    this->board[3][6] = Cell('n');
    this->board[3][7] = Cell('n');

    this->board[4][0] = Cell('n');
    this->board[4][1] = Cell('n');
    this->board[4][2] = Cell('n');
    this->board[4][3] = Cell('n');
    this->board[4][4] = Cell('n');
    this->board[4][5] = Cell('n');
    this->board[4][6] = Cell('n');
    this->board[4][7] = Cell('n');

    this->board[5][0] = Cell('r');
    this->board[5][1] = Cell('n');
    this->board[5][2] = Cell('r');
    this->board[5][3] = Cell('n');
    this->board[5][4] = Cell('r');
    this->board[5][5] = Cell('n');
    this->board[5][6] = Cell('r');
    this->board[5][7] = Cell('n');

    this->board[6][0] = Cell('n');
    this->board[6][1] = Cell('r');
    this->board[6][2] = Cell('n');
    this->board[6][3] = Cell('r');
    this->board[6][4] = Cell('n');
    this->board[6][5] = Cell('r');
    this->board[6][6] = Cell('n');
    this->board[6][7] = Cell('r');

    this->board[7][0] = Cell('r');
    this->board[7][1] = Cell('n');
    this->board[7][2] = Cell('n');
    this->board[7][3] = Cell('r');
    this->board[7][4] = Cell('n');
    this->board[7][5] = Cell('r');
    this->board[7][6] = Cell('n');
    this->board[7][7] = Cell('r');
}


bool Board::validateMove() {
    return false;
}

Cell *Board::getBoard() {
    return *this->board;
}

