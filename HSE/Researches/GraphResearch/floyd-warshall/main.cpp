#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <cstring>
#include <fstream>

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

int main() {
    std::ifstream inputFile("floyd_warshall.txt");

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

        auto start = std::chrono::high_resolution_clock::now();

        FloydWarshall(matrix);

        auto elapsed = std::chrono::high_resolution_clock::now() - start;

        int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

        std::cout << nanoseconds;

        return 0;
    }
}