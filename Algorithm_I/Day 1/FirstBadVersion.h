#ifndef ALGORITHM_I_FIRSTBADVERSION_H
#define ALGORITHM_I_FIRSTBADVERSION_H

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version);

class FirstBadVersion {
public:
    int firstBadVersion(int n) {
        int low = 0;
        int high = n;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (isBadVersion(mid) && !isBadVersion(mid - 1))
                return mid;

            if (!isBadVersion(mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return mid;
    }
};

#endif//ALGORITHM_I_FIRSTBADVERSION_H
