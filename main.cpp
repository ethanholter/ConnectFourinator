#include <iostream>
#include "src/ConnectFour/ConnectFour.h"
#include "src/ConnectFourBot/ConnectFourBot.h"
#include <iostream>

int main(int argc, const char** argv) {
    std::cout << "Begin Connect4!\n" << std::endl;
    ConnectFour game(true);
    ConnectFourBot bot;

    while(game.checkWin() == -1) {
        game.printBoard();
        std::cout << "Player's turn\n";
        int column;
        std::cin >> column;
        game.completeMove(column);
    }

    game.printBoard();
    std::cout << "Player " << game.checkWin() + 1 << " wins!\n";

    return 0;
}