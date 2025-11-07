#include <iostream>
#include <cstdlib>
#include "../include/Board.h"
#include "../include/Player.h"
#include "../include/AI.h"
#include "../include/Utils.h"

// g++ -std=c++17 -Wall src/main.cpp src/Board.cpp src/Player.cpp src/AI.cpp -o connect4.exe
// .\connect4.exe


int main() {
    srand((unsigned)time(NULL));

    char board[HEIGHT][WIDTH];
    createBoard(board);
    std::string headline = drawBoard(board);

    int AI;
    std::cout << "Select AI Level (0=Human vs Human, 1=Easy): ";
    std::cin >> AI;

    Player p1 = createPlayer(1, AI);
    Player p2 = createPlayer(2, AI);

    bool gameOn = true;
    while (gameOn) {
        // Player 1 turn
        p1 = getPlayerMove(p1, headline, board);
        insertPiece(p1, board);
        drawBoard(board);
        if (checkWin(p1, board)) {
            std::cout << "\n" << p1.name << " wins!\n";
            break;
        }
        if (checkTie(board)) {
            std::cout << "\nTie! No one won.\n";
            break;
        }

        // Player 2 / AI turn
        if (AI == 0)
            p2 = getPlayerMove(p2, headline, board);
        else if (AI == 1)
            p2 = AI_easy(headline, p2, WIDTH, board);

        insertPiece(p2, board);
        drawBoard(board);
        if (checkWin(p2, board)) {
            std::cout << "\n" << p2.name << " wins!\n";
            break;
        }
        if (checkTie(board)) {
            std::cout << "\nTie! No one won.\n";
            break;
        }
    }

    std::cout << "\nGame over. Thanks for playing!\n";
    return 0;
}
