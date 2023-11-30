#include <chrono>
#include <fstream>
#include <iostream>
#include <queue>

constexpr int INF = std::numeric_limits<int>::max();

void spfa(const std::vector<std::vector<int>> &graph, int start, int n,
          std::vector<int> &distance) {
    std::vector<int> count(n, 0);  // Количество посещений вершин
    std::vector<bool> inQueue(n, false);  // Флаг, указывающий, находится ли вершина в очереди
    std::queue<int> q;  // Очередь для BFS

    distance[start] = 0;
    q.push(start);
    inQueue[start] = true;
    count[start]++;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        inQueue[curr] = false;

        for (int dest = 0; dest < n; ++dest) {
            if (graph[curr][dest] != INF) {
                int weight = graph[curr][dest];

                if (distance[curr] + weight < distance[dest]) {
                    distance[dest] = distance[curr] + weight;

                    if (!inQueue[dest]) {
                        q.push(dest);
                        inQueue[dest] = true;
                        count[dest]++;

                        if (count[dest] > n) {
                            std::cout << "Negative cycle detected!" << std::endl;
                            return;
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    std::ifstream inputFile("spfa.txt");

    if (inputFile.is_open()) {
        std::vector<int> numbers;
        int num;
        while (inputFile >> num) {
            numbers.push_back(num);
        }

        inputFile.close();  // Закрываем файл
        int rows = numbers[0];
        int columns = numbers[1];

        std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));

        int index = 2;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                matrix[i][j] = numbers[index];
                index += 1;
            }
        }

        std::vector<int> distance(rows, INF);

        auto start = std::chrono::high_resolution_clock::now();

        spfa(matrix, 0, rows, distance);

        auto elapsed = std::chrono::high_resolution_clock::now() - start;

        int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

        std::cout << nanoseconds;
        return 0;
    }
}