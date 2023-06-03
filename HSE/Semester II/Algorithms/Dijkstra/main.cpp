#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <set>

using std::cin;
using std::cout;

// Псевдокод: https://ru.wikipedia.org/wiki/Алгоритм_Дейкстры

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
    // std::set<std::pair<uint64_t
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
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    uint64_t n, m;
    cin >> n >> m;

    std::vector<std::vector<Edge>> graph(n);

    for (uint64_t i = 0; i < m; ++i) {
        uint64_t u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    std::vector<uint64_t> distances(n);
    dijkstra(graph, distances);

    for (uint64_t i = 1; i < n; ++i) {
        cout << distances[i] << "\n";
    }

    return 0;
}