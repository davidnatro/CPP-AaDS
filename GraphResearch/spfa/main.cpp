#include <chrono>
#include <iostream>
#include <queue>

constexpr int INF = std::numeric_limits<int>::max();

void spfa(const std::vector<std::vector<int>> &graph, int start, int n,
          std::vector<int> &distance) {
  std::vector<int> count(n, 0);// Количество посещений вершин
  std::vector<bool> inQueue(n, false);// Флаг, указывающий, находится ли вершина в очереди
  std::queue<int> q;// Очередь для BFS

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
  int rows = std::stoi(argv[1]);
  int columns = std::stoi(argv[2]);

  std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns, 0));

  int index = 3;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      matrix[i][j] = std::stoi(argv[index]);
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
