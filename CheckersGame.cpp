//
// Created by Sawyer on 1/11/2021.
//

#include "CheckersGame.h"
#include <iostream>
#include <cmath>

void CheckersGame::userInput(std::string& startMove, std::string& endMove) {
	std::cout << "Input move (e.g., A6 B5): ";
	std::cin >> startMove;
	std::cin >> endMove;
}

void CheckersGame::translate(char startArray[2], char endArray[2], int startConvert[2], int endConvert[2]) {

	switch (startArray[0]) {
		case 'A':
			startConvert[0] = 0;
			break;
		case 'B':
			startConvert[0] = 1;
			break;
		case 'C':
			startConvert[0] = 2;
			break;
		case 'D':
			startConvert[0] = 3;
			break;
		case 'E':
			startConvert[0] = 4;
		case 'F':
			startConvert[0] = 5;
			break;
		case 'G':
			startConvert[0] = 6;
			break;
		case 'H':
			startConvert[0] = 7;
			break;
		default:
			startConvert[0] = 8;
	}
	switch (startArray[1]) {
		case '1':
			startConvert[1] = 0;
			break;
		case '2':
			startConvert[1] = 1;
			break;
		case '3':
			startConvert[1] = 2;
			break;
		case '4':
			startConvert[1] = 3;
			break;
		case '5':
			startConvert[1] = 4;
		case '6':
			startConvert[1] = 5;
			break;
		case '7':
			startConvert[1] = 6;
			break;
		case '8':
			startConvert[1] = 7;
			break;
		default:
			startConvert[1] = 8;
	}
	
	switch (endArray[0]) {
		case 'A':
			endConvert[0] = 0;
			break;
		case 'B':
			endConvert[0] = 1;
			break;
		case 'C':
			endConvert[0] = 2;
			break;
		case 'D':
			endConvert[0] = 3;
			break;
		case 'E':
			endConvert[0] = 4;
		case 'F':
			endConvert[0] = 5;
			break;
		case 'G':
			endConvert[0] = 6;
			break;
		case 'H':
			endConvert[0] = 7;
			break;
		default:
			endConvert[0] = 8;
	}
	switch (endArray[1]) {
		case '1':
			endConvert[1] = 0;
			break;
		case '2':
			endConvert[1] = 1;
			break;
		case '3':
			endConvert[1] = 2;
			break;
		case '4':
			endConvert[1] = 3;
			break;
		case '5':
			endConvert[1] = 4;
		case '6':
			endConvert[1] = 5;
			break;
		case '7':
			endConvert[1] = 6;
			break;
		case '8':
			endConvert[1] = 7;
			break;
		default:
			endConvert[1] = 8;
	}
}

bool CheckersGame::verifyInput(int startConvert[2], int endConvert[2]) {
	if ((((startConvert[0] >= 0) && (startConvert[0] <= 7)) && ((endConvert[0] >= 0) && (endConvert[0] <= 7))) && (((startConvert[1] >= 0) && (startConvert[1] <= 7)) && ((endConvert[1] >= 0) && (endConvert[1] <= 7)))) {
		return true;
	}
	else {
		return false;
	}
}

void CheckersGame::movePiece(int *startPos, int *endPos) {
    Cell* start = &gameBoard.board[startPos[0]][startPos[1]];
    Cell* end = &gameBoard.board[endPos[0]][endPos[1]];

    if (std::abs(startPos[0] - endPos[0]) == 2) {
        int middleX = std::abs(startPos[0] - endPos[0]) / 2;
        int middleY = std::abs(startPos[1] - endPos[1]) / 2;

        Cell* middle = &gameBoard.board[middleX][middleY];
        middle->setIsOccupied(false);
        middle->setPieceColor('n');
    }

    end->setPieceColor(start->getPieceColor());
    end->setIsOccupied(start->getIsOccupied());

    start->setIsOccupied(false);
    start->setPieceColor('n');
}

void CheckersGame::changeTurn(char& currentMove) {
	if (currentMove == 'b') {
		currentMove = 'r';
	}
	else {
		currentMove = 'b';
	}
}

void CheckersGame::mainLoop() {
	std::string startMove;
	std::string endMove;
	char startArray[2];
	char endArray[2];
	int startConvert[2];
	int endConvert[2];
	int pieceCount[2];

	this->gameBoard.resetBoard();
	this->gameBoard.printBoard();

    int winner = 0;
    while (winner == 0) {
        switch(currentMove) {
            case 'r':
                std::cout << "Red, what is your move: " << std::endl;
                break;
            case 'b':
                std::cout << "Black, what is your move: " << std::endl;
                break;
        }

		bool checkInput = false;
		bool checkInput2 = false;

		//USER INPUT & INPUT VALIDATION
		do {
			userInput(startMove, endMove);

			startArray[0] = startMove[0];
			startArray[1] = startMove[1];
			endArray[0] = endMove[0];
			endArray[1] = endMove[1];

			translate(startArray, endArray, startConvert, endConvert);

			checkInput = verifyInput(startConvert, endConvert);

			checkInput2 = this->gameBoard.validateMove(startConvert, endConvert, currentMove);

			if (!checkInput) {
				std::cout << "ERROR: Unrecognised input" << std::endl;
			}
			if (!checkInput2) {
				std::cout << "ERROR: Invalid move" << std::endl;
			}

		} while (!checkInput || !checkInput2);

		movePiece(startConvert, endConvert);
		changeTurn(currentMove);

		winner = this->gameBoard.checkWinner(pieceCount);
    }
	
	if (pieceCount[0] == 0) {
		std::cout << "Red wins!" << std::endl;
		winner = 1;
	}
	else if (pieceCount[1] == 0) {
		std::cout << "Black wins!" << std::endl;
		winner = 2;
	}
}