#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;

constexpr int kInf = INT32_MAX;

int fordFulkerson(const std::vector<std::vector<int>>& capacity, const int source, const int stok) {
    int n = capacity.size();
    std::vector<std::vector<int>> rem_capacity(capacity);

    std::vector<int> parent(n);

    int max_flow = 0;

    while (true) {
        for (int& num : parent) {
            num = -1;
        }

        std::queue<int> q;
        q.push(source);
        parent[source] = -2;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; ++v) {
                if (parent[v] == -1 && rem_capacity[u][v] > 0) {
                    q.push(v);
                    parent[v] = u;
                }
            }
        }

        if (parent[stok] == -1) {
            break;
        }

        int path_flow = kInf;
        int v = stok;
        while (v != source) {
            int u = parent[v];
            path_flow = std::min(path_flow, rem_capacity[u][v]);
            v = u;
        }

        v = stok;
        while (v != source) {
            int u = parent[v];
            rem_capacity[u][v] -= path_flow;
            rem_capacity[v][u] += path_flow;
            v = u;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> capacity(n, std::vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
        capacity[u - 1][v - 1] += c;
    }

    int source = 0;
    int stok = n - 1;

    int max_flow = fordFulkerson(capacity, source, stok);

    cout << max_flow << '\n';

    return 0;
}
