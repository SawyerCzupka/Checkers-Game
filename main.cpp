#include <iostream>
#include "CheckersGame.h"

int main() {
    CheckersGame Game;
    std::string startMove;
    std::string endMove;
    bool checkInput = false;
    char startArray[2];
    char endArray[2];
    int startConvert[2];
    int endConvert[2];

    //USER INPUT & INPUT VALIDATION
    do {
        

        Game.userInput(startMove, endMove);

        startArray[0] = startMove[0];
        startArray[1] = startMove[1];
        endArray[0] = endMove[0];
        endArray[1] = endMove[1];

        Game.translate(startArray, endArray, startConvert, endConvert);

        checkInput = Game.verifyInput(startConvert, endConvert);

        if (!checkInput) {
            std::cout << "ERROR: Unrecognised input" << std::endl;
        }

    } while (!checkInput);
    
    std::cout << startConvert[0] << startConvert[1] << endConvert[0] << endConvert[1] << std::endl;

    return 0;
}
