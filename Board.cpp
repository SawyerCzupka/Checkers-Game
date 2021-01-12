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

bool validateMove() {
    return false;
}
