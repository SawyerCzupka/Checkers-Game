//
// Created by Sawyer on 1/11/2021.
//

#include "Board.h"
#include "Cell.h"

#include <iostream>

void Board::printBoard() {
    for (int i = 0; i < 8; i++) {
        std::cout << "-----------------------------------------------" << std::endl;
        for (int j = 0; j < 8; j++) {
            Cell current = this->board[i][j];

            switch (current.getPieceColor()) {
                case 'r':
                    std::cout << "r";
                    break;
                case 'b':
                    std::cout << "b";
                    break;
                case 'n':
                    std::cout << " ";
                    break;
                default:
                    std::cout << "Error" << std::endl;
                    break;
            }

            std::cout << "  |  ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
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
    this->board[7][2] = Cell('r');
    this->board[7][3] = Cell('n');
    this->board[7][4] = Cell('r');
    this->board[7][5] = Cell('n');
    this->board[7][6] = Cell('r');
    this->board[7][7] = Cell('n');
}


bool Board::validateMove(int startConvert[2], int endConvert[2], char currentMove) {
    Cell current = this->board[startConvert[0]][startConvert[1]];
    Cell next = this->board[endConvert[0]][endConvert[1]];

    if (std::abs(startConvert[0] - endConvert[0]) == 2) {
        int middleX = std::abs(startConvert[0] - endConvert[0]) / 2;
        int middleY = std::abs(startConvert[1] - endConvert[1]) / 2;
        Cell middle = this->board[middleX][middleY];

        if (!current.getIsOccupied()) {  //Check if cell is occupied
            if (currentMove == 'b') {  //Check if player is using correct piece
                if (current.getPieceColor() == 'b') {   //Check if used piece is correct
                    if (next.getPieceColor() == 'n') {  //Check if end cell empty
                        if (middle.getPieceColor() == 'r') {    //Check if capturing enemy
                            return true;
                        }
                    }
                }
            }
            if (currentMove == 'r') {
                if (current.getPieceColor() == 'r') {
                    if (next.getPieceColor() == 'n') {
                        if (middle.getPieceColor() == 'b') {
                            return true;
                        }
                    }
                }
            }

        }
    }

    if (std::abs(startConvert[0] - endConvert[0]) == 1) {
        if (!current.getIsOccupied()) {
            if (currentMove == 'b') {
                if (current.getPieceColor() == 'b') {
                    if (next.getPieceColor() == 'n') {
                        return true;
                    }
                }
            }
            if (currentMove == 'r') {
                if (current.getPieceColor() == 'r') {
                    if (next.getPieceColor() == 'n') {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int Board::checkWinner(int pieceCount[2]) {
    int totalB = 0;
    int totalR = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Cell current = this->board[i][j];

            if (current.getIsOccupied()) {
                switch (current.getPieceColor()) {
                    case 'r':
                        totalR++;
                        break;
                    case 'b':
                        totalB++;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    pieceCount[0] = totalB;
    pieceCount[1] = totalR;

    if (totalB == 0 || totalR == 0) {
        return 1;
    }
    else {
        return 0;
    }
}