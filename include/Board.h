#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "Player.h"
#include "Utils.h"  

extern const std::string alphabet;

void createBoard(char board[HEIGHT][WIDTH]);
std::string drawBoard(const char board[HEIGHT][WIDTH]);
bool checkWin(const Player &player, char board[HEIGHT][WIDTH]);
bool checkTie(const char board[HEIGHT][WIDTH]);
void insertPiece(const Player &player, char board[HEIGHT][WIDTH]);

#endif
