#include "../include/Board.h"
#include <iostream>

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void createBoard(char board[HEIGHT][WIDTH]) {
    for (int h = 0; h < HEIGHT; h++)
        for (int w = 0; w < WIDTH; w++)
            board[h][w] = '.';
}

std::string drawBoard(char board[HEIGHT][WIDTH]) {
    std::string headline = "";
    for (int w = 0; w < WIDTH; w++)
        headline += " " + std::string(1, alphabet[w]) + " ";
    std::cout << "\n" << headline << "\n";
    for (int h = 0; h < HEIGHT; h++) {
        for (int w = 0; w < WIDTH; w++) {
            std::cout << ' ' << board[h][w];
            if (w == WIDTH - 1) std::cout << '\n';
            else std::cout << ' ';
        }
    }
    std::cout << headline << "\n";
    return headline;
}

void insertPiece(const Player &player, char board[HEIGHT][WIDTH]) {
    int col = alphabet.find(player.input);
    for (int row = HEIGHT - 1; row >= 0; row--) {
        if (board[row][col] == '.') {
            board[row][col] = player.symbol;
            break;
        }
    }
}

bool checkWin(const Player &player, char board[HEIGHT][WIDTH]) {
    char s = player.symbol;
    // Vertical
    for (int h = 0; h < HEIGHT - 3; h++)
        for (int w = 0; w < WIDTH; w++)
            if (board[h][w]==s && board[h+1][w]==s && board[h+2][w]==s && board[h+3][w]==s)
                return true;
    // Horizontal
    for (int h = 0; h < HEIGHT; h++)
        for (int w = 0; w < WIDTH - 3; w++)
            if (board[h][w]==s && board[h][w+1]==s && board[h][w+2]==s && board[h][w+3]==s)
                return true;
    // Diagonal (\)
    for (int h = 0; h < HEIGHT - 3; h++)
        for (int w = 0; w < WIDTH - 3; w++)
            if (board[h][w]==s && board[h+1][w+1]==s && board[h+2][w+2]==s && board[h+3][w+3]==s)
                return true;
    // Diagonal (/)
    for (int h = 3; h < HEIGHT; h++)
        for (int w = 0; w < WIDTH - 3; w++)
            if (board[h][w]==s && board[h-1][w+1]==s && board[h-2][w+2]==s && board[h-3][w+3]==s)
                return true;
    return false;
}

bool checkTie(char board[HEIGHT][WIDTH]) {
    for (int w = 0; w < WIDTH; w++)
        if (board[0][w] == '.') return false;
    return true;
}
