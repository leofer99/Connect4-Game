#include "../include/AI.h"
#include "../include/Board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Player AI_easy(const std::string &headline, Player player, int width, char board[][7]) {
    int col;
    do {
        col = rand() % width;
    } while (board[0][col] != '.');
    player.input = alphabet[col];
    std::cout << player.name << " plays column " << player.input << "\n";
    insertPiece(player, board);
    return player;
}
