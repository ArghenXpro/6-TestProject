#include <iostream>
#include <string>
#include <algorithm>

class Player {
public:
    std::string name;
    int score;

    Player() : name(""), score(0) {}
    Player(const std::string& name, int score) : name(name), score(score) {}

    bool operator<(const Player& other) const {
        return score > other.score; // Сортировка по убыванию очков
    }
};

int main() {
    int numPlayers;
    std::cout << "Enter the number of players: ";
    std::cin >> numPlayers;

    Player* players = new Player[numPlayers];

    for (int i = 0; i < numPlayers; ++i) {
        std::cout << "Enter name for player " << i + 1 << ": ";
        std::cin >> players[i].name;
        std::cout << "Enter score for player " << i + 1 << ": ";
        std::cin >> players[i].score;
    }

    // Сортировка игроков по убыванию очков
    std::sort(players, players + numPlayers);

    std::cout << "\nPlayers sorted by score:\n";
    for (int i = 0; i < numPlayers; ++i) {
        std::cout << players[i].name << ": " << players[i].score << std::endl;
    }

    delete[] players;
    return 0;
}
