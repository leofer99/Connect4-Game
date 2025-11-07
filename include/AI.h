#ifndef AI_H
#define AI_H
#include "Player.h"
#include <string>

Player AI_easy(const std::string &headline, Player player, int width, char board[HEIGHT][WIDTH]);
Player AI_medium(const std::string &headline, Player player1, Player player2, int width, char board[HEIGHT][WIDTH], char test_board[HEIGHT][WIDTH]);
void AI_hard(Player playerAI, char board[][7], char test_board[HEIGHT][WIDTH], double values[], Player playerHuman);

#endif
