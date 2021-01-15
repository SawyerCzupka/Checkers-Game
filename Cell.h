//
// Created by Sawyer on 1/11/2021.
//

#ifndef CHECKERS_GAME_CELL_H
#define CHECKERS_GAME_CELL_H


class Cell {
public:
    explicit Cell(char pieceColor);

    bool getIsOccupied() const;

    char getPieceColor() const;

    Cell(){}; //Dummy constructor

private:
    bool isOccupied{};
public:
    void setIsOccupied(bool isOccupied);

    void setPieceColor(char pieceColor);

private:
    char pieceColor; // 'r' 'b' or 'n'
};


#endif //CHECKERS_GAME_CELL_H
