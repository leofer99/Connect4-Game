#include "../include/Board.h"
#include "../include/Player.h"
#include <iostream>

Player createPlayer(int num, int AI) {
    Player player;
    player.num = num;
    player.winner = false;

    if (num == 2 && AI != 0) {
        if (AI == 1) player.name = "Computer_Easy";
        else if (AI == 2) player.name = "Computer_Medium";
        else if (AI == 3) player.name = "Computer_Hard";
    } else {
        std::cout << "\nPlayer " << num << " name: ";
        std::cin >> player.name;
    }

    player.symbol = (num == 1) ? 'X' : 'O';
    return player;
}

Player getPlayerMove(const Player &player, const std::string &headline, char board[6][7]) {
    Player p = player;
    while (true) {
        std::string str;
        std::cout << "\n" << player.name << ", choose a column (A - " << headline.back() << "): ";
        std::cin >> str;
        if (str.size() == 1) {
            char col = toupper(str[0]);
            if (headline.find(col) != std::string::npos) {
                int idx = headline.find(col);
                if (board[0][idx] == '.') {
                    p.input = col;
                    return p;
                } else std::cout << "Column full. Try again.\n";
            } else std::cout << "Invalid column.\n";
        } else std::cout << "Only one letter allowed.\n";
    }
}
