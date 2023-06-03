#include <iostream>
#include <vector>

using std::cin;
using std::cout;

// Псевдокод: https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm

const int64_t kInf = INT64_MAX;

std::vector<std::vector<int64_t>> floydWarshall(const std::vector<std::vector<int64_t>> &graph,
                                                int64_t num_vertices) {
    std::vector<std::vector<int64_t>> distances(graph);

    for (int64_t k = 0; k < num_vertices; ++k) {
        for (int64_t i = 0; i < num_vertices; ++i) {
            for (int64_t j = 0; j < num_vertices; ++j) {
                if (distances[i][k] != kInf && distances[k][j] != kInf &&
                    distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    return distances;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, m;
    cin >> n >> m;

    std::vector<std::vector<int64_t>> graph(n, std::vector<int64_t>(n, kInf));

    for (int64_t i = 0; i < m; ++i) {
        int64_t u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    std::vector<std::vector<int64_t>> shortest_distances = floydWarshall(graph, n);

    for (int64_t u = 0; u < n; ++u) {
        for (int64_t v = 0; v < n; ++v) {
            if (u != v && shortest_distances[u][v] == kInf) {
                cout << u << " " << v << " -1\n";
            } else if (u != v) {
                cout << u << " " << v << " " << shortest_distances[u][v] << "\n";
            }
        }
    }

    return 0;
}
