#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

void input(std::pair<int, int> segments[], const int segments_size, int points[],
           const int points_size) {
    int segment1, segment2;
    for (int i = 0; i < segments_size; ++i) {
        cin >> segment1 >> segment2;
        segments[i] = std::make_pair(segment1, segment2);
    }

    //    for (int i = 0; i < points_size; ++i) {
    //        cin >> points[i];
    //    }
}

void print(const int data[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << data << " ";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int segments_size, points_size;
    cin >> segments_size >> points_size;

    std::pair<int, int> segments[segments_size];
    int points[0];

    input(segments, segments_size, points, points_size);

    std::sort(segments, segments + segments_size,
              [](std::pair<int, int> f, std::pair<int, int> s) { return f.first < s.first; });

    int point, count;
    for (int i = 0; i < points_size; ++i) {
        cin >> point;
        count = 0;
        for (int j = 0; j < segments_size; ++j) {
            if (point < segments[j].first) {
                break;
            }
            if (point <= segments[j].second) {
                count += 1;
            }
        }
        cout << count << " ";
    }

    return 0;
}
