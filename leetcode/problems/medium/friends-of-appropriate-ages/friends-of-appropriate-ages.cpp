#include "friends-of-appropriate-ages.h"

int FriendsOfAppropriateAges::numFriendRequests(std::vector<int> &ages) {
    int count = 0;
    int age_count[121]{0};

    for (const int age : ages) {
        age_count[age] += 1;
    }

    for (int i = 1; i <= 120; ++i) {
        for (int j = 1; j <= 120; ++j) {
            if (isSendingRequest(i, j)) {
                if (i == j) {
                    count += age_count[i] * (age_count[i] - 1);
                } else {
                    count += age_count[i] * age_count[j];
                }
            }
        }
    }
    return count;
}

bool FriendsOfAppropriateAges::isSendingRequest(int x, int y) {
    bool first = y <= 0.5 * x + 7;
    bool second = y > x;
    bool third = y > 100 && x < 100;

    return !first && !second && !third;
}
