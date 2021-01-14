//
// Created by Sawyer on 1/11/2021.
//

#ifndef CHECKERS_GAME_CHECKERSGAME_H
#define CHECKERS_GAME_CHECKERSGAME_H

#include <iostream>

class CheckersGame {
	public:
		void userInput(std::string& startMove, std::string& endMove);
		void translate(char startArray[2], char endArray[2], int startConvert[2], int endConvert[2]);
		bool verifyInput(int startConvert[2], int endConvert[2]);

	private:
		std::string startMove;
		std::string endMove;
};


#endif //CHECKERS_GAME_CHECKERSGAME_H
