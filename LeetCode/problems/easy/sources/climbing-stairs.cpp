#include "../headers/climbing-stairs.h"

int ClimbingStairs::climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    int data[n];

    data[0] = 1;
    data[1] = 2;

    for (int i = 2; i < n; ++i) {
        data[i] = data[i - 2] + data[i - 1];
    }

    return data[n - 1];
}