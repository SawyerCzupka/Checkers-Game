//
// Created by Sawyer on 1/11/2021.
//

#include "Cell.h"

bool Cell::getIsOccupied() const {
    return isOccupied;
}

char Cell::getPieceColor() const {
    return pieceColor;
}

Cell::Cell(char pieceColor) : pieceColor(pieceColor) {
    if (pieceColor == 'n') {
        !this->isOccupied;
    }

    else {
        this->isOccupied;
    }
}

void Cell::setIsOccupied(bool isOccupied) {
    Cell::isOccupied = isOccupied;
}

void Cell::setPieceColor(char pieceColor) {
    Cell::pieceColor = pieceColor;
}
