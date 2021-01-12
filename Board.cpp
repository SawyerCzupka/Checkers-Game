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
    this->board[0][0] = 'n';
    this->board[0][1] = 'b';
    this->board[0][2] = 'n';
    this->board[0][3] = 'b';
    this->board[0][4] = 'n';
    this->board[0][5] = 'b';
    this->board[0][6] = 'n';
    this->board[0][7] = 'b';

    this->board[1][0] = 'b';
    this->board[1][1] = 'n';
    this->board[1][2] = 'b';
    this->board[1][3] = 'n';
    this->board[1][4] = 'b';
    this->board[1][5] = 'n';
    this->board[1][6] = 'b';
    this->board[1][7] = 'n';

    this->board[2][0] = 'n';
    this->board[2][1] = 'b';
    this->board[2][2] = 'n';
    this->board[2][3] = 'b';
    this->board[2][4] = 'n';
    this->board[2][5] = 'b';
    this->board[2][6] = 'n';
    this->board[2][7] = 'b';

    this->board[3][0] = 'n';
    this->board[3][1] = 'n';
    this->board[3][2] = 'n';
    this->board[3][3] = 'n';
    this->board[3][4] = 'n';
    this->board[3][5] = 'n';
    this->board[3][6] = 'n';
    this->board[3][7] = 'n';

    this->board[4][0] = 'n';
    this->board[4][1] = 'n';
    this->board[4][2] = 'n';
    this->board[4][3] = 'n';
    this->board[4][4] = 'n';
    this->board[4][5] = 'n';
    this->board[4][6] = 'n';
    this->board[4][7] = 'n';

    this->board[5][0] = 'r';
    this->board[5][1] = 'n';
    this->board[5][2] = 'r';
    this->board[5][3] = 'n';
    this->board[5][4] = 'r';
    this->board[5][5] = 'n';
    this->board[5][6] = 'r';
    this->board[5][7] = 'n';

    this->board[6][0] = 'n';
    this->board[6][1] = 'r';
    this->board[6][2] = 'n';
    this->board[6][3] = 'r';
    this->board[6][4] = 'n';
    this->board[6][5] = 'r';
    this->board[6][6] = 'n';
    this->board[6][7] = 'r';

    this->board[7][0] = 'r';
    this->board[7][1] = 'n';
    this->board[7][2] = 'r';
    this->board[7][3] = 'n';
    this->board[7][4] = 'r';
    this->board[7][5] = 'n';
    this->board[7][6] = 'r';
    this->board[7][7] = 'n';
}

bool Board::validateMove() {
    return false;
}

