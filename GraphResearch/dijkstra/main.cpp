#include <iostream>
#include <chrono>
#include <queue>

const uint64_t kInf = UINT64_MAX;

struct Edge {
    uint64_t to;
    uint64_t weight;
};

struct Compare {
    bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
        return lhs.second > rhs.second;
    }
};

void dijkstra(const std::vector<std::vector<Edge>>& graph, std::vector<uint64_t>& distances) {
    uint64_t n = graph.size();
    distances.assign(n, kInf);
    distances[0] = 0;

    std::priority_queue<std::pair<uint64_t, uint64_t>, std::vector<std::pair<uint64_t, uint64_t>>,
                        Compare>
        pq;

    pq.push({0, 0});

    while (!pq.empty()) {
        uint64_t curr_dist = pq.top().first;
        uint64_t curr_vertex = pq.top().second;
        pq.pop();

        if (curr_dist > distances[curr_vertex]) {
            continue;
        }

        for (const Edge& edge : graph[curr_vertex]) {
            uint64_t new_dist = curr_dist + edge.weight;
            if (new_dist < distances[edge.to]) {
                distances[edge.to] = new_dist;
                pq.push({new_dist, edge.to});
            }
        }
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    // algo

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds;

    return 0;
}
