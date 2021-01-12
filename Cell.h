//
// Created by Sawyer on 1/11/2021.
//

#ifndef CHECKERS_GAME_CELL_H
#define CHECKERS_GAME_CELL_H


class Cell {
public:
    bool getIsOccupied() const;

    char getPieceColor() const;

private:
    bool isOccupied;
    char pieceColor; // 'r' or 'b'
};


#endif //CHECKERS_GAME_CELL_H
