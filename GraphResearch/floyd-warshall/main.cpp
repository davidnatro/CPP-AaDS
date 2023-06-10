#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <cstring>

const int kInf = std::numeric_limits<int>::max();

// Функция для реализации алгоритма Флойда-Уоршелла
void FloydWarshall(std::vector<std::vector<int>>& graph) {
    int numNodes = graph.size();

    // Проходим по всем узлам в качестве промежуточного узла
    for (int k = 0; k < numNodes; ++k) {
        // Проходим по всем парам узлов (i, j) и обновляем расстояние
        for (int i = 0; i < numNodes; ++i) {
            for (int j = 0; j < numNodes; ++j) {
                // Если существует путь через узел k, сокращающий расстояние, то обновляем его
                if (graph[i][k] != kInf && graph[k][j] != kInf &&
                    graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
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
            if (std::strcmp(argv[index], "INF") == 0) {
                matrix[i][j] = kInf;
            } else {
                matrix[i][j] = std::stoi(argv[index]);
            }

            index += 1;
        }
    }

    auto start = std::chrono::high_resolution_clock::now();

    FloydWarshall(matrix);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds;

    return 0;
}
