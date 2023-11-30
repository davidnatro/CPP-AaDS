#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
stack<int> resultStack;
vector<string> items;

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        if (!visited[adj[node][i]]) {
            dfs(adj[node][i]);
        }
    }
    resultStack.push(node);
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    items.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    while (!resultStack.empty()) {
        cout << items[resultStack.top()] << "\n";
        resultStack.pop();
    }

    return 0;
}
