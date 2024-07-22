#ifndef FIND_THE_WINNER_OF_THE_CIRCULAR_GAME_HPP
#define FIND_THE_WINNER_OF_THE_CIRCULAR_GAME_HPP

// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

#include <list>
#include <queue>

class FindTheWinnerOfTheCircularGame {
public:
    int findTheWinner(int n, int k) const;

private:
    int findTheWinnerList(int n, int k) const;

    int findTheWinnerQueue(int n, int k) const;
};

#endif