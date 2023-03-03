#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;

class Interval {
    double begin_;
    double end_;
    double weight_;

public:
    Interval(const double begin, const double end, const double weight) {
        this->begin_ = begin;
        this->end_ = end;
        this->weight_ = weight;
    }

    double getBegin() const {
        return begin_;
    }

    double getEnd() const {
        return end_;
    }

    double getWeight() const {
        return weight_;
    }
};

int binarySearch(const std::vector<Interval> &intervals, const int index) {
    int left = 0;
    int right = index - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (intervals[mid].getEnd() <= intervals[index].getBegin()) {
            if (intervals[mid + 1].getEnd() <= intervals[index].getBegin()) {
                left = mid + 1;
            } else {
                return mid;
            }
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int intervals_size;
    cin >> intervals_size;

    std::vector<Interval> intervals;

    double begin, end, weight;
    for (int i = 0; i < intervals_size; ++i) {
        cin >> begin >> end >> weight;
        intervals.emplace_back(begin, end, weight);
    }
    cout.flush();

    std::sort(intervals.begin(), intervals.end(),
              [](const Interval &first, const Interval &second) {
                  return first.getEnd() - second.getEnd() < 0;
              });

    std::vector<double> results(intervals_size);
    results[0] = intervals[0].getWeight();

    for (int i = 1; i < intervals_size; ++i) {
        double w = intervals[i].getWeight();

        int index = binarySearch(intervals, i);
        if (index != -1) {
            w += results[index];
        }

        results[i] = std::max(w, results[i - 1]);
    }

    cout << std::fixed << std::setprecision(4) << results[intervals_size - 1];

    return 0;
}
