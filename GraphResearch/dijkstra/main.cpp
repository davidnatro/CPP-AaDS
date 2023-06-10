#include <iostream>
#include <vector>
#include <limits>
#include <chrono>

const int kInf = std::numeric_limits<int>::max();

// Функция для реализации алгоритма Дейкстры
void dijkstra(const std::vector<std::vector<int>>& graph, int startNode,
              std::vector<int>& distances) {
    int numNodes = graph.size();

    // Инициализация расстояний до всех узлов как бесконечность, кроме стартового узла
    distances.assign(numNodes, kInf);
    distances[startNode] = 0;

    // Массив для отслеживания посещенных узлов
    std::vector<bool> visited(numNodes, false);

    for (int i = 0; i < numNodes - 1; ++i) {
        int minDistance = kInf;
        int minNode = -1;

        // Находим узел с наименьшим расстоянием
        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                minNode = j;
            }
        }

        // Помечаем узел как посещенный
        visited[minNode] = true;

        // Обновляем расстояния до всех соседних узлов
        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && graph[minNode][j] != 0 && distances[minNode] != kInf) {
                int newDistance = distances[minNode] + graph[minNode][j];
                if (newDistance < distances[j]) {
                    distances[j] = newDistance;
                }
            }
        }
    }
}

int main(int argc, char** argv) {
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

    std::vector<int> distances(rows);

    auto start = std::chrono::high_resolution_clock::now();

    dijkstra(matrix, 0, distances);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds;

    return 0;
}
