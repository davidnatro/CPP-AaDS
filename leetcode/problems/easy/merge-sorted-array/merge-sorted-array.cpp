#include "merge-sorted-array.h"

void MergeSortedArray::merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i -= 1;
        } else {
            nums1[k] = nums2[j];
            j -= 1;
        }

        k -= 1;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        j -= 1;
        k -= 1;
    }
}