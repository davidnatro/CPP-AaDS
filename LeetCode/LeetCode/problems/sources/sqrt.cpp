#include "../headers/sqrt.h"

int Solution::mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    int start = 1;
    int end = x / 2;
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;

        if (x / mid == mid) {
            return mid;
        }

        if (x / mid < mid) {
            end = mid - 1;
        } else if (x / mid > mid) {
            start = mid + 1;
        }
    }

    return end;
}