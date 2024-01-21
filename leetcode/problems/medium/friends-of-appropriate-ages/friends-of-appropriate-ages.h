#ifndef LEETCODE_PROBLEMS_MEDIUM_HEADERS_FRIENDS_OF_APPROPRIATE_AGES_H_
#define LEETCODE_PROBLEMS_MEDIUM_HEADERS_FRIENDS_OF_APPROPRIATE_AGES_H_

// https://leetcode.com/problems/friends-of-appropriate-ages/

#include <vector>

class FriendsOfAppropriateAges {
public:
    int numFriendRequests(std::vector<int>& ages);

private:
    bool isSendingRequest(int x, int y);
};

#endif
