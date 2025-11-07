#ifndef PLAYER_H
#define PLAYER_H
#include <string>

struct Player {
    int num;
    std::string name;
    char symbol;
    char input;
    bool winner;
};

Player createPlayer(int num, int AI);
Player getPlayerMove(const Player &player, const std::string &headline, char board[HEIGHT][WIDTH]);

#endif
