#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;

int main() {
    int n, m;
    cin >> n >> m;

    std::vector<std::string> names(n);
    std::vector<int> visited(n, 0);
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    int id;
    std::string name;

    for (int i = 0; i < n; ++i) {
        cin >> id;
        cin.ignore(1);
        std::getline(cin, name);
        names[id] = name;
    }

    int from, to;
    for (int i = 0; i < m; ++i) {
        cin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }



    return 0;
}
