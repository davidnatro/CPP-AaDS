#include <iostream>
#include <vector>
#include <limits>

using std::cin;
using std::cout;

constexpr int64_t kInf = INT64_MAX;
constexpr int64_t kMin = INT64_MIN;

struct Edge {
    int64_t from;
    int64_t to;
    int64_t weight;

    Edge(int64_t from, int64_t to, int64_t weight) : from(from), to(to), weight(weight) {
    }
};

std::vector<int64_t> bellmanFordShortestPaths(int64_t n, const std::vector<Edge>& edges) {
    std::vector<int64_t> dist(n, kInf);
    dist[0] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (const Edge& edge : edges) {
            if (dist[edge.from] != kInf && dist[edge.from] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }

    for (const Edge& edge : edges) {
        if (dist[edge.from] != kInf && dist[edge.from] + edge.weight < dist[edge.to]) {
            dist[edge.to] = kMin;
        }
    }

    return dist;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    std::vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    std::vector<int64_t> shortest_paths = bellmanFordShortestPaths(n, edges);

    for (int i = 1; i < n; ++i) {
        if (shortest_paths[i] == kMin) {
            cout << "-inf"
                 << "\n";
        } else {
            cout << shortest_paths[i] << "\n";
        }
    }

    return 0;
}
