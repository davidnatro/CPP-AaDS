#include "find-the-winner-of-the-circular-game.hpp"

int FindTheWinnerOfTheCircularGame::findTheWinner(int n, int k) const {
    return findTheWinnerQueue(n, k);
}

int FindTheWinnerOfTheCircularGame::findTheWinnerList(int n, int k) const {
    std::list<int> data;
    for (int i = 1; i <= n; ++i) {
        data.emplace_back(i);
    }

    std::list<int>::iterator iterator = data.begin();
    while (data.size() > 1) {
        for (int count = 1; count < k; ++count) {
            ++iterator;
            if (iterator == data.end()) {
                iterator = data.begin();
            }
        }
        iterator = data.erase(iterator);
        if (iterator == data.end()) {
            iterator = data.begin();
        }
    }

    return data.back();
}

int FindTheWinnerOfTheCircularGame::findTheWinnerQueue(int n, int k) const {
    std::queue<int> data;
    for (int i = 1; i <= n; ++i) {
        data.push(i);
    }

    while (data.size() > 1) {
        for (int i = 1; i < k; ++i) {
            int player = data.front();
            data.pop();
            data.push(player);
        }
        data.pop();
    }

    return data.back();
}